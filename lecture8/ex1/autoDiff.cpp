#include<iostream>
#include<cmath>
#include<vector>

class ADExpression{

	public:

		virtual double evaluate() const = 0;
		virtual double derivative() const = 0;
};


class Constant : public ADExpression{

	public:

		Constant(const double v) : val(v){}

		double evaluate() const override{
			return val;
		}

		double derivative() const override{
			return 0;
		}

	private:

		double val;

};


class Var : public ADExpression{

	public:

		Var(const double v) : val(v) {}

		double evaluate() const override{
			return val;
		}

		double derivative() const override{
			return 1.0;
		}

	private:

		double val;
};


class Sum : public  ADExpression{

	public:

		Sum(const ADExpression &a, const ADExpression &b) : a(a), b(b) {}

		double evaluate() const override{

			return a.evaluate() + b.evaluate();
		}

		double derivative() const override{

			return a.derivative() + b.derivative();
		}

	private:

		const ADExpression &a;
		const ADExpression &b;
};




int main(){

	Var x{2.0};

	auto f = Sum(Sum(x, x), Constant(1.0));

	std::cout << f.evaluate() << std::endl;
	std::cout << f.derivative() << std::endl;

	return 0;
}









