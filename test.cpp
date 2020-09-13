#define BOOST_TEST_MODULE MyString

#include <iostream>
#include "mystring.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

using namespace std;
using namespace stringexercise;

BOOST_AUTO_TEST_SUITE(MyString)

BOOST_AUTO_TEST_CASE(Constructors) {
	// Test all 3 constructors with empty strings.
	mystring emptyMyString1 = mystring();
	BOOST_CHECK_EQUAL(emptyMyString1.length(), 0);
	BOOST_CHECK_EQUAL(emptyMyString1.is_empty(), true);
	BOOST_CHECK_EQUAL(emptyMyString1.c_str()[0], '\0');

	const char* emptyCString = "";
	mystring emptyMyString2 = mystring(emptyCString);
	BOOST_CHECK_EQUAL(emptyCString, emptyMyString2.c_str());
	BOOST_CHECK_EQUAL(emptyMyString1, emptyMyString2);

	string emptyString = "";
	mystring emptyMyString3 = mystring(emptyString);
	BOOST_CHECK_EQUAL(emptyString, emptyMyString3.c_str());
	BOOST_CHECK_EQUAL(emptyMyString2, emptyMyString3);

	// Test the constructors with non-empty strings.
	const char* abcCString = "abc";
	mystring abcMyString1 = mystring(abcCString);
	BOOST_CHECK_EQUAL(abcCString, abcMyString1.c_str());

	string abcString = "abc";
	mystring abcMyString2 = mystring(abcString);
	BOOST_CHECK_EQUAL(abcString, abcMyString2.c_str());
	BOOST_CHECK_EQUAL(abcMyString1, abcMyString2);
}

BOOST_AUTO_TEST_CASE(ModifyingMemberFunctions) {
	// Test the += operator.
	mystring container = mystring("");
	mystring addendMyString = "abc";
	container += addendMyString;
	BOOST_CHECK_EQUAL(container, "abc");
	BOOST_CHECK_EQUAL(container, addendMyString);

	const char* addendCString = "def";
	container += addendCString;
	BOOST_CHECK_EQUAL(container, "abcdef");

	char addendChar = 'g';
	container += addendChar;
	BOOST_CHECK_EQUAL(container, "abcdefg");

	// Test the = and [] operators
	mystring myString1 = mystring("My String");
	mystring myString2 = myString1;
	BOOST_CHECK_EQUAL(myString1, myString2);
	BOOST_CHECK_EQUAL("My String", myString2);
	BOOST_CHECK_EQUAL(myString1.c_str(), myString2.c_str());
	BOOST_CHECK_EQUAL(myString1[3], 'S');
	BOOST_CHECK_EQUAL(myString1[3], myString2[3]);
}

BOOST_AUTO_TEST_CASE(ConstantMemberFunctions) {
	// Test the swap function.
	mystring myString1 = mystring("My String 1");
	mystring myString2 = mystring("My String 2");
	myString1.swap(myString2);
	BOOST_CHECK_EQUAL(myString1, "My String 2");
	BOOST_CHECK_EQUAL(myString2, "My String 1");
}

BOOST_AUTO_TEST_CASE(FriendFunctions) {
	// Test the output stream operator.
	mystring myString = mystring("string");
	boost::test_tools::output_test_stream output;
	output << myString;
	BOOST_CHECK(!output.is_empty(false));
	BOOST_CHECK(output.check_length(6, false));
	BOOST_CHECK(output.is_equal(myString.c_str()));

	// Test the comparison operators.
	mystring same1 = mystring("same");
	mystring same2 = mystring("same");
	BOOST_CHECK_EQUAL(same1 == same2, true);
	BOOST_CHECK_EQUAL(same1 != same2, false);

	mystring different = mystring("different");
	BOOST_CHECK_EQUAL(same1 == different, false);
	BOOST_CHECK_EQUAL(same1 != different, true);

	mystring abc = mystring("abc");
	mystring bcd = mystring("bcd");
	BOOST_CHECK_EQUAL(abc < bcd, true);
	BOOST_CHECK_EQUAL(abc <= bcd, true);
	BOOST_CHECK_EQUAL(bcd > abc, true);
	BOOST_CHECK_EQUAL(bcd >= abc, true);

	mystring abc2 = mystring("abc");
	BOOST_CHECK_EQUAL(abc <= abc2, true);
	BOOST_CHECK_EQUAL(abc >= abc2, true);
	BOOST_CHECK_EQUAL(abc >= abc2, true);
}

BOOST_AUTO_TEST_CASE(NonMemberFunctions) {
	// Test the + operator.
	mystring myString1 = mystring("ABC");
	mystring myString2 = mystring("DEF");
	BOOST_CHECK_EQUAL(myString1 + myString2, "ABCDEF");

	const char* cString = "BBQ";
	BOOST_CHECK_EQUAL(myString1 + cString, "ABCBBQ");
	BOOST_CHECK_EQUAL(cString + myString2, "BBQDEF");
}

BOOST_AUTO_TEST_SUITE_END()