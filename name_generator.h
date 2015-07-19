//
// Created by Aidan Campbell on 7/18/15.
//
#pragma once

#include <iosfwd>
#include <set>

std::string read_text(std::string);
std::set<std::string> split(std::string input);
bool is_female();
std::string get_random_element_from(std::set<std::string>);