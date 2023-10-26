#include<iostream>
#include<cmath>
#include<vector>


class DataSource{

	public:

		// friend class DataTransformer;

		std::vector<double> &get_data(){
			return data;
		}

		const std::vector<double> &get_data() const{
			return data;
		}

		virtual void read_data() = 0;

		virtual ~DataSource(){}


	protected:
		std::vector<double> data;
};


class FileDataSource : public DataSource{

	public:
		FileDataSource(const std::string &name) : filename(name){
			file.open(filename);
		}

		void read_data() override{

			double new_val;

			while(file >> new_val){
				data.push_back(new_val);
			}
		}


	private:
		std::string filename;
		std::ifstream file;
};


class DataTransformer{

	public:

		DataTransformer(DataSource &s)
		  :  source(s) {}

		virtual void transform() = 0;

		virtual ~DataTransformer() {}


	protected:

		double:
			DataSource &source;
};


class LinearScaling : public DataTransformer{

	public:

		LinearScaling(const double &k) : scaling_factor(k) {}

		void transform() override{

			/*
			for(unsigned int i = 0; i < source.get_data().size(); i++){

				source.get_data()[i] *= k;
			}
			*/

			//range based for loop
			for(double &x : source.get_data())
				x *= scaling_factor;
		}
};


class LogTransformer : public DataTransformer{



};


class StandardScaling : public DataTransformer{



};








