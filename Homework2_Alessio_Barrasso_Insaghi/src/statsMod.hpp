#ifndef STATSMOD__
#define STATSMOD__

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
#include<variant>
#include<optional>
#include<numeric>
#include<cmath> 

typedef unsigned int uint;

class statsMod{
public:

    // Constructors
    statsMod(const std::string &filePath);
    statsMod(std::map<std::string, std::vector<std::optional<std::variant<double, std::string>>>> &data);
    statsMod(const statsMod& other);
    statsMod& operator=(const statsMod& other);

    // Slicing the data-set
    statsMod operator()(int start, int end);
    statsMod operator()(std::string var);
    statsMod operator()(std::vector<std::string> vars);
    statsMod find(const std::string &var, const std::string &value);

    // Methods
    std::map<std::string, double> mean(std::vector<std::string> vars = {}, int start = 0, int end = -1) const;
    std::map<std::string, double> var(std::vector<std::string> vars = {}, int start = 0, int end = -1) const;
    std::map<std::string, double> sd(std::vector<std::string> vars = {}, int start = 0, int end = -1) const;
    std::map<std::string, double> median(std::vector<std::string> vars = {}, int start = 0, int end = -1) const;
    std::map<std::string, uint> freq(const std::string &var) const;
    double corr(const std::vector<std::string> &vars, int start = 0, int end = -1) const;
    
    // Utilities
    void colnames() const; // prints name of the variables of the data-frame.
    bool isVar(std::vector<std::string> vars) const; // checks if list of variables is present in data-frame colnames.
    void dropNA(); // removes all rows with at least one NA value.
    void head(const uint n = 10); // prints first n lines of the data-frame.
    void summary(); // brief summary of the data-set.

    // Attributes
    mutable std::map<std::string, std::vector<std::optional<std::variant<double, std::string>>>> data; // std::map containing the data
    std::vector<std::string> columns; // names of the variables.
    std::vector<std::string> numCols; // names of the numerical variables.
    std::vector<std::string> catCols; // names of the categoriacal variables.
    int ncol; // number of columns
    int nrow; // number of rows
};

#endif