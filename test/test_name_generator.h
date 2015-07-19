//
// Created by Aidan Campbell on 7/19/15.
//

#pragma once
#include "../name_generator.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <assert.h>

void test_read_from_file(){
    std::string result = read_text("sample_test.txt");
    assert (result.compare("lorem ipsum dolor sit amet") == 0);
}

void test_split(){
    std::string input = "hi hello";
    assert ((*(split(input).begin())).compare("hi") == 0);
    assert ((*(split(input).end())).compare("hello") == 0);
}