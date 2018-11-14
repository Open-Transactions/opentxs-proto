#!/usr/bin/env python
# Copyright (c) 2018 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

"""This post-processing creates something closer to an idiomatic
Python package.

Usage:

import opentxsproto as pb

mf = pb.MoveFunds()

MoveFunds_pb2 (and the internal-only MoveFunds__pb2) are still available.

"""

import glob
import re
from setuptools import setup

PREFIX = "opentxsproto"

# If we're in an opentxsproto package, we need to qualify internal imports
IMPORT_SIBLING = re.compile(r"\nimport (\w+) as (\w+)")
LOCAL_FROM_IMPORT = re.compile(r"\nfrom ([A-Z]\w+) import \*")

def rewrite_file(filename):
    """Rewrite a file, replacing imports with package-specific imports"""
    with open(filename) as read_file:
        whole_file_string = read_file.read()

    whole_file_string = IMPORT_SIBLING.sub(
        r"\nimport opentxsproto.\1 as \2", whole_file_string)
    whole_file_string = LOCAL_FROM_IMPORT.sub(
        r"\nfrom opentxsproto.\1 import *", whole_file_string)

    with open(filename, "w") as write_file:
        write_file.write(whole_file_string)


MODULE_FROM_FILENAME = re.compile(f"{PREFIX}/(\\w+)_pb2.py")

def extract_module_name_from_filename(m):
    """Given a filename from the module, extract the module name"""
    res = MODULE_FROM_FILENAME.match(m)
    assert res
    return res.group(1)

MODULES = []

# Rewrite files, saving module names
for f in glob.glob(f"{PREFIX}/*_pb2.py"):
    rewrite_file(f)
    module = extract_module_name_from_filename(f)
    MODULES.append(module)


# Generate an __init__ which imports all the modules.
with open("opentxsproto/__init__.py", "w") as f:
    for module in MODULES:
        # f.write(f"import {PREFIX}.{module}_pb2 as {module}\n")
        f.write(f"from {PREFIX}.{module}_pb2 import *\n")

setup(name='opentxsproto',
      version='0.3',
      description='Open-Transactions Canonical Protbuf Definition Library',
      author='Justus Ranvier',
      author_email='justus@opentransactions.org',
      url='https://github.com/Open-Transactions/opentxs-proto',
      packages=['opentxsproto'],
      install_requires=['protobuf'],
     )
