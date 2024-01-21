#include <gtest/gtest.h>
#include "../../src/simpleFraction/simpleFraction.hpp"


TEST(DecimalConvert, Convert2){
    SimpleFraction a(6, 2);
    EXPECT_EQ(a.getDecimal(), 3);
}

TEST(DecimalConvert, Convert3){
    SimpleFraction a(1, 2);
    EXPECT_EQ(a.getDecimal(), 0.5);
}


TEST(EQUALS, EQUAL1){
    SimpleFraction a(3, 5);
    SimpleFraction b(6, 10);
    EXPECT_EQ(a == b, true);
}

TEST(EQUALS, EQUAL2){
    SimpleFraction a(4, 8);
    SimpleFraction b(1, 2);
    EXPECT_EQ(a == b, true);
}

TEST(GT, GT1){
    SimpleFraction a(2, 3);
    SimpleFraction b(4, 5);
    EXPECT_EQ(a > b, false);
}

TEST(GT, GT2){
    SimpleFraction a(6, 3);
    SimpleFraction b(1, 2);
    EXPECT_EQ(a > b, true);
}


TEST(LT, LT1){
    SimpleFraction a(2, 3);
    SimpleFraction b(7, 8);
    EXPECT_EQ(a < b, true);
}

TEST(LT, LT2){
    SimpleFraction a(6, 3);
    SimpleFraction b(1, 4);
    EXPECT_EQ(a < b, false);
}


TEST(GT_EQ, GT_EQ1){
    SimpleFraction a(4, 5);
    SimpleFraction b(8, 10);
    EXPECT_EQ(a >= b, true);
}

TEST(GT_EQ, GT_EQ2){
    SimpleFraction a(2, 3);
    SimpleFraction b(6, 8);
    EXPECT_EQ(a >= b, false);
}

TEST(LT_EQ, LT_EQ1){
    SimpleFraction a(1, 6);
    SimpleFraction b(2, 5);
    EXPECT_EQ(a <= b, true);
}

TEST(LT_EQ, LT_EQ2){
    SimpleFraction a(1, 8);
    SimpleFraction b(3, 24);
    EXPECT_EQ(a <= b, true);
}

TEST(MultS, MultS1){
    SimpleFraction a(2, 5);
    SimpleFraction b(6, 4);

    SimpleFraction temp = a.mult(b);

    EXPECT_EQ(temp.getNumerator(), 12);
    EXPECT_EQ(temp.getDenumerator(), 20);
}

TEST(MultS, MultS2){
    SimpleFraction a(1, 2);
    SimpleFraction b(6, 1);

    SimpleFraction temp = a.mult(b);

    EXPECT_EQ(temp.getNumerator(), 6);
    EXPECT_EQ(temp.getDenumerator(), 2);
}

TEST(DivS, DivS1){
    SimpleFraction a(2, 3);
    SimpleFraction b(1, 2);

    SimpleFraction temp = a.div(b);

    EXPECT_EQ(temp.getNumerator(), 4);
    EXPECT_EQ(temp.getDenumerator(), 3);
}

TEST(DivS, DivS2){
    SimpleFraction a(4, 5);
    SimpleFraction b(3,4);

    SimpleFraction temp = a.div(b);

    EXPECT_EQ(temp.getNumerator(), 16);
    EXPECT_EQ(temp.getDenumerator(), 15);
}

TEST(AddS, AddS1){
    SimpleFraction a(1, 6);
    SimpleFraction b(2, 5);

    SimpleFraction temp = a.add(b);

    EXPECT_EQ(temp.getNumerator(), 17);
    EXPECT_EQ(temp.getDenumerator(), 30);
}

TEST(AddS, AddS2){
    SimpleFraction a(1, 2);
    SimpleFraction b(7, 3);

    SimpleFraction temp = a.add(b);

    EXPECT_EQ(temp.getNumerator(), 17);
    EXPECT_EQ(temp.getDenumerator(), 6);
}

TEST(StaticAdd, StaticAdd1){
    SimpleFraction result = SimpleFraction::add(SimpleFraction(2, 3), SimpleFraction(1, 8));
    EXPECT_EQ(result.getNumerator(), 19);
    EXPECT_EQ(result.getDenumerator(), 24);
}

TEST(StaticAdd, StaticAdd2){
    SimpleFraction result = SimpleFraction::add(SimpleFraction(1, 4), SimpleFraction(3, 2));
    EXPECT_EQ(result.getNumerator(), 14);
    EXPECT_EQ(result.getDenumerator(), 8);
}

TEST(StaticSub, StaticSub1){
    SimpleFraction result = SimpleFraction::sub(SimpleFraction(1, 2),SimpleFraction(4, 5));
    EXPECT_EQ(result.getNumerator(),-3);
    EXPECT_EQ(result.getDenumerator(), 10);
}

TEST(StaticSub, StaticSub2){
    SimpleFraction result = SimpleFraction::sub(SimpleFraction(3, 5), SimpleFraction(1, 8));
    EXPECT_EQ(result.getNumerator(), 19);
    EXPECT_EQ(result.getDenumerator(), 40);
}


TEST(StaticMult, StaticMult1){
    SimpleFraction result = SimpleFraction::mult(SimpleFraction(1, 2), SimpleFraction(3, 4));
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenumerator(), 8);
}

TEST(StaticMult, StaticMult2){
    SimpleFraction  result = SimpleFraction::mult(SimpleFraction(-1, 5), SimpleFraction(2, 3));
    EXPECT_EQ(result.getNumerator(), -2);
    EXPECT_EQ(result.getDenumerator(), 15);
}

TEST(StaticDiv, StaticDiv1){
    SimpleFraction result = SimpleFraction::div(SimpleFraction(1,2), SimpleFraction(5, 7));
    EXPECT_EQ(result.getNumerator(), 7);
    EXPECT_EQ(result.getDenumerator(), 10);                                                                                                                                                                                   
}

TEST(StaticDiv, StaticDiv2){
    SimpleFraction result = SimpleFraction::div(SimpleFraction(-3, 2), SimpleFraction(1, 5));
    EXPECT_EQ(result.getNumerator(), -15);
    EXPECT_EQ(result.getDenumerator(), 2);
}

TEST(OparatorMult, OperatorMult1){
    SimpleFraction result = SimpleFraction(2, 7) * SimpleFraction(1,3);
    EXPECT_EQ(result.getNumerator(), 2);
    EXPECT_EQ(result.getDenumerator(), 21);
}

TEST(OperatorMult, OperatorMult2){
    SimpleFraction result = SimpleFraction(1, 5) * SimpleFraction(7, 6);
    EXPECT_EQ(result.getNumerator(), 7);
    EXPECT_EQ(result.getDenumerator(), 30);
}

TEST(OperatorDiv, OperatorDiv1){
    SimpleFraction result = SimpleFraction(3, 4) / SimpleFraction(5, 6);
    EXPECT_EQ(result.getNumerator(), 18);
    EXPECT_EQ(result.getDenumerator(), 20);
}

TEST(OperatorDiv, OperatorDiv2){
    SimpleFraction result = SimpleFraction(8, 3) / SimpleFraction(1, 2);
    EXPECT_EQ(result.getNumerator(), 16);
    EXPECT_EQ(result.getDenumerator(), 3);
}

TEST(OperatorAdd, OperatorAdd1){
    SimpleFraction result = SimpleFraction(1,2) + SimpleFraction(5, 6);
    EXPECT_EQ(result.getNumerator(), 16);
    EXPECT_EQ(result.getDenumerator(), 12);
}

TEST(OperatorAdd, OperatorAdd2){
    SimpleFraction result = SimpleFraction(-7, 5) + SimpleFraction(5, 6);
    EXPECT_EQ(result.getNumerator(), -17);
    EXPECT_EQ(result.getDenumerator(), 30); 
}

TEST(OperatorSub, OperatorSub1){
    SimpleFraction result = SimpleFraction(1, 2) - SimpleFraction(5,6);
    EXPECT_EQ(result.getNumerator(), -4);
    EXPECT_EQ(result.getDenumerator(), 12);
}

TEST(OperatorSub, OperatorSub2){
    SimpleFraction result = SimpleFraction(-4, 5) - SimpleFraction(1, 2);
    EXPECT_EQ(result.getNumerator(), -13);
    EXPECT_EQ(result.getDenumerator(), 10);
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}