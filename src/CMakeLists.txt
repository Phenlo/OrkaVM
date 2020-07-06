cmake_minimum_required(VERSION 3.10)
project(OrkaVM_src)

set(ORKA_SOURCES main.c orka_env_init.c)
add_executable(orka ${ORKA_SOURCES})
