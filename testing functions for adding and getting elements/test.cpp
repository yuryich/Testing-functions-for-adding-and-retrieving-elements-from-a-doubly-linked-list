#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "list.hpp" 

TEST_CASE("Testing PushBack and PushFront", "[list]") {
	List list;

	SECTION("PushBack works correctly") {
		list.PushBack(10);
		list.PushBack(20);
		list.PushBack(30);
		REQUIRE(list.Size() == 3);

		REQUIRE(list.PopBack() == 30);
		REQUIRE(list.PopBack() == 20);
		REQUIRE(list.PopBack() == 10);
		REQUIRE(list.Empty());
	}

	SECTION("PushFront works correctly") {
		list.PushFront(10);
		list.PushFront(20);
		list.PushFront(30);
		REQUIRE(list.Size() == 3);

		REQUIRE(list.PopFront() == 30);
		REQUIRE(list.PopFront() == 20);
		REQUIRE(list.PopFront() == 10);
		REQUIRE(list.Empty());
	}
}

TEST_CASE("Testing PopBack and PopFront on empty list", "[list]") {
	List list;

	SECTION("PopBack throws on empty list") {
		REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
	}

	SECTION("PopFront throws on empty list") {
		REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
	}
}

TEST_CASE("Complex scenario test", "[list]") {
	List list;

	// PushBack and PushFront combined
	list.PushBack(10);
	list.PushFront(20);
	list.PushBack(30);
	list.PushFront(40);

	REQUIRE(list.Size() == 4);

	// PopFront and PopBack combined
	REQUIRE(list.PopFront() == 40);  // Порядок: 40, 20, 10, 30
	REQUIRE(list.PopBack() == 30);   // Порядок: 20, 10
	REQUIRE(list.PopFront() == 20);  // Порядок: 10
	REQUIRE(list.PopBack() == 10);   // Пустой список
	REQUIRE(list.Empty());
}