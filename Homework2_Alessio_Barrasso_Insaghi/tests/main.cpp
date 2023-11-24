#include"../src/statsMod.hpp"

int main(){

    ///////////////////////////////
    // Part 1: Statistics Module //
    ///////////////////////////////

    // Building the object .
    statsMod df{"shopping_trends_updated.csv"};

    // Removing rows with at least one NA value (if any are present).
    df.dropNA();

    // Obtaining the number of columns of the data-set.
    std::cout << "\n----------------------------------------------------------------------------\n" << std::endl;
    std::cout << "Number of columns stored in the object: "<< df.ncol << "\n" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << "\n" << std::endl;

    // Printing the name of the columns.
    std::cout << "Name of the variables: " << std::endl;
    df.colnames();
    std::cout << "\n" << std::endl;

    // The data-set contains 18 columns, which makes it hard to visualize it neatly.
    // In this case, we select a subset of the columns to showcase the functioning
    // of the statistics module. The object lends itself to be sliced both on the columns
    // and the rows (more on that later) by simply calling the operator() with a vector
    // of the columns the user wants to keep.
    std::vector<std::string> sub_vars = {"Age", "Purchase Amount (USD)", "Review Rating", "Previous Purchases", "Payment Method", "Shipping Type"};
    statsMod sub_df = df(sub_vars);

    // Getting a brief description of the data_set.
    sub_df.summary();
    std::cout << "----------------------------------------------------------------------------" << "\n" << std::endl;

    // Obtaining the correlation between pairs of numerical variables.
    std::cout << "Correlations: " << std::endl;
    std::vector<std::string> cor_vars = {"Previous Purchases", "Age"};
    std::vector<std::string> cor_vars2 = {"Review Rating", "Purchase Amount (USD)"};
    std::cout << "Corr(Previous Purchases, Age) = " << sub_df.corr(cor_vars) << std::endl;
    std::cout << "Corr(Review Rating, Purchase Amount) = " << sub_df.corr(cor_vars2) << "\n" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << "\n" << std::endl;

    // Counting the occurrences of every possible value for a categorical variable.
    std::map<std::string, uint> payment_counts = sub_df.freq("Payment Method");
    std::cout << "Payment methods: " << std::endl;
    for(const auto &pair : payment_counts) 
        std::cout << pair.first << ": " << pair.second << std::endl;
    std::cout << std::endl;

    // Obtaining the subset of the rows that contain a specific value in a given column.
    // Obtaining only the observations for the people who paid Cash.
    statsMod cash_df = sub_df.find("Payment Method", "Cash");
    std::cout << "Subset of the people who paid cash. " << std::endl;
    cash_df.head();

    // Overloading the operator() also allows to slice the data-set on the rows, calling
    // df(i, j) returns a statsMod object containing the rows between indexes i and j.
    statsMod sub_df_small = sub_df(100, 199);
    std::cout << "\n----------------------------------------------------------------------------\n" << std::endl;
    std::cout << "Number of rows of the small data-set: " << sub_df_small.nrow << "\n" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << "\n" << std::endl;
    
    // This way of slicing the data-set, which returns another instance of the same class 
    // containing the subset of interest of the data, allows for complex instruction via concatenation
    // of simpler ones. With the next line of code we obtain the subset of the observations between 
    // line 100 and line 1100 who paid cash, and whose shipping type was type Express.
    statsMod special_df = sub_df(100, 1100).find("Payment Method", "Cash").find("Shipping Type", "Express");
    std::cout << "Subset of the observations between line 100 and 1100, who paid cash and whose shipping type was type Express. " << std::endl;
    special_df.head();
}