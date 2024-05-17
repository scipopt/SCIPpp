# usage: extract_solvingstats.py FULL_PATH_TO_

import argparse
from caseconverter import macrocase
import CppHeaderParser
from typing import Optional


def create_object_name(c_name: str) -> str:
    assert c_name.startswith('SCIPget')
    return macrocase(c_name.split('SCIPget')[1]).replace("_L_P_", "_LP_")


def extract_description(doxygen: str) -> Optional[str]:
    if '@return' not in doxygen:
        return None
    res = doxygen.split("@return")[1]
    if '\n' in res:
        res = res.split('\n')[0].strip()
    if res.startswith("the"):
        res = res[4:]
    return res.strip()


parser = argparse.ArgumentParser()
parser.add_argument("header", help="Full path to scip_solvingstats.h", type=str)
args = parser.parse_args()

header = CppHeaderParser.CppHeader(args.header)
for fn in header.functions:
    name = fn['name']
    params = fn['parameters']
    if name.startswith("SCIPget") and len(params) == 1:
        prm = params[0]
        assert prm['raw_type'] == 'SCIP'
        doc = fn['doxygen']
        if descr := extract_description(doc):
            print(f"//! {descr}")
        rtype = fn['returns'].split(' ')[1]
        print(f"static const Statistic<{rtype}> {create_object_name(name)} {{ &{name} }};")
