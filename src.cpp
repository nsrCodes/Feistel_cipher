#include <iostream>
#include <vector>

//function for deistel round
class Feistel()
{
	std::string message;
	int num_keys;
	std::vector<int> keys;
	void Feistel()
	{
		// Specifying innput
		std::cout<<"Enter the secret message: ";
		std::cin>>message;
		std::cout<<"\n Specify Number of keys: ";
		std::cin>>num_keys;
		std::cout<<"\n Enter Keys one by one: \n";
		for(int i=0;i<num_keys;i++)
		{
			int key;
			std::cin>>key;
			std::cout<<std::endl;
			keys.push_back(key);
		}

		//Process
		std::cout<<"\n---------------------Process-----------------------------";
		std::cout<<"\nOriginal message: \n"<<message;
		std::string enc_msg{Encode(message,keys)};
		std::cout<<"\n Encoded messgae: "<<enc_msg;
		std::cout<<"\n Decoded messgae: "<<eDecode(enc_msg,keys);

	}
	std::string F(std::string buffer,double key)
	{
		//function working with keys
		str::string processed_buffer;
		for(auto itr = buffer.rbegin(); itr != buffer.rend(); itr++ )
			processed_buffer.push_back((*itr)+key)	
		return processed_buffer;
	}


	std::string Encode(std::string msg,std::vector<double> keys;)
	{
		std::string  encoded{msg};
		int no_of_rounds = keys.size();

		// split in half
		//specify left and right containers
		std::string left,right;
		encoded.copy(left,no_of_rounds/2,0);
		encoded.copy(right,no_of_rounds,no_of_rounds/2);
		

		//run feistel round in loops
		for(auto key = keys.begin();key != keys.end(); key++)
		{	//for each instance in loop
			std::string buffer;
			
			/*Convert the string to binary*/
			///the processs of conversion
			buffer=F(right,key);

			// left= left XOR buffer
			// left , right = right , left 
			right.swap(left)
		}
		// left , right = right , left 
		right.swap(left)

		encoded{left+right};
		return encoded;
	}

	std::string Decode(std::string msg,std::vector<double> keys;)
	{
		std::string  decoded{msg};
		int no_of_rounds = keys.size();

		// split in half
		//specify left and right containers
		std::string left,right;
		decoded.copy(left,no_of_rounds/2,0);
		decoded.copy(right,no_of_rounds,no_of_rounds/2);
		

		//run feistel round in loops
		for(auto key = keys.rbegin();key != keys.rend(); key++)
		{	//for each instance in loop
			std::string buffer;
			buffer=F(right,key);
			// left= left XOR buffer
			// left , right = right , left 
			right.swap(left)
		}
		// left , right = right , left 
		right.swap(left)

		decoded{left+right}
		return decoded;
	}
}

int main()
{
	//Class declaration
	return 0;
}