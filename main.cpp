#include <iostream>
#include<fstream>
using namespace std;

class User {
	string _name;
	string _login;
	string _pass;

public:
	User(string name, string login, string pass) :_name(name), _login(login), _pass(pass) {}

	friend fstream& operator >>(fstream& is, User& obj);
	friend ostream& operator <<(ostream& os, const User& obj);
};

fstream& operator >>(fstream& is, User& obj)
{
	is >> obj._name;
	is >> obj._login;
	is >> obj._pass;
	return is;
}
ostream& operator <<(ostream& os, const User& obj)
{
	os << obj._name;
	os << ' ';
	os << obj._login;
	os << ' ';
	os << obj._pass;
	return os;
}

class Message {
	string _text;
	string _sender;
	string _receiver;

public:
	Message(string text, string sender, string receiver) :_text(text), _sender(sender), _receiver(receiver) {}

	friend fstream& operator >>(fstream& is, Message& obj);
	friend ostream& operator <<(ostream& os, const Message& obj);
};
fstream& operator >>(fstream& is, Message& obj)
{
	is >> obj._text;
	is >> obj._sender;
	is >> obj._receiver;
	return is;
}
ostream& operator <<(ostream& os, const Message& obj)
{
	os << obj._text;
	os << ' ';
	os << obj._sender;
	os << ' ';
	os << obj._receiver;
	return os;
}

int main() {

	fstream users_file = fstream("users.txt", ios::in | ios::out);
	fstream messages_file = fstream("messages.txt", ios::in | ios::out);

	if (users_file) {
		User user("John", "qwerty", "12345");
		users_file << user << endl;
		users_file.seekg(0, ios_base::beg);
		users_file >> user;
		cout << user << endl;
	}
	if (messages_file) {
		Message msg("Hello", "Andrew", "John");
		messages_file << msg << endl;
		messages_file.seekg(0, ios_base::beg);
		messages_file >> msg;
		cout << msg << endl;
	}
	else
	{
		cout << "Could not open files !" << '\n';
		return 0;
	}
}