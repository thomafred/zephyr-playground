cmake_minimum_required(VERSION 3.8.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(CONF_FILE "prj.conf")

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(si7021_test)

target_sources(app PRIVATE src/main.c)
