#include <rbt.h>
#include <catch.hpp>

SCENARIO ("init", "[init]")
{
  RBT<int> tree;
  REQUIRE(tree.root_() == tree.nil_());
}

SCENARIO("insert with search", "[ins+srch]")
{
  RBT<int> tree;
  tree.insert(2);
  REQUIRE(tree.search(2) != 0);
}

SCENARIO("insert with search ¹2", "[ins+srch_2]")
{
  RBT<int> tree;
  tree.insert(5);
  tree.insert(1);
  tree.insert(8);
  REQUIRE(tree._root() == tree.search(5));
  REQUIRE(tree._color(5) == 1);
  REQUIRE(tree._color(1) == 0);
  REQUIRE(tree._color(8) == 0);
  REQUIRE(tree.search(5) != 0);
  REQUIRE(tree.search(1) != 0);
  REQUIRE(tree.search(8) != 0);
}

SCENARIO("insert with search ¹3", "[ins+srch_3]")
{
  RBT<int> tree;
  tree.insert(6);
  tree.insert(4);
  tree.insert(2);
  tree.insert(10);
  tree.insert(1);
  REQUIRE(tree._root() == tree.search(4));
  REQUIRE(tree._color(4) == 1);
  REQUIRE(tree._color(2) == 1);
  REQUIRE(tree._color(6) == 1);
  REQUIRE(tree._color(1) == 0);
  REQUIRE(tree._color(10) == 0);
  REQUIRE(tree.search(4) != 0);
  REQUIRE(tree.search(2) != 0);
  REQUIRE(tree.search(6) != 0);
  REQUIRE(tree.search(1) != 0);
  REQUIRE(tree.search(10) != 0);
}

SCENARIO ("insert with search ¹4", "[ins+srch_4]")
{
  RBT<int> tree;
  tree.insert(10);
  tree.insert(1);
  tree.insert(6);
  tree.insert(19);
  tree.insert(7);
  tree.insert(3);
  tree.insert(8);
  REQUIRE(tree._root() == tree.search(6));
  REQUIRE(tree._color(6) == 1);
  REQUIRE(tree._color(1) == 1);
  REQUIRE(tree._color(10) == 0);
  REQUIRE(tree._color(3) == 0);
  REQUIRE(tree._color(7) == 1);
  REQUIRE(tree._color(19) == 1);
  REQUIRE(tree._color(8) == 0);
  REQUIRE(tree.search(6) != 0);
  REQUIRE(tree.search(1) != 0);
  REQUIRE(tree.search(10) != 0);
  REQUIRE(tree.search(3) != 0);
  REQUIRE(tree.search(7) != 0);
  REQUIRE(tree.search(19) != 0);
  REQUIRE(tree.search(8) != 0);
}