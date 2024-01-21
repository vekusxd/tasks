#include <gtest/gtest.h>
#include "../../src/vector/vector.hpp"

TEST(getVectorLength , Test1){
    Vector vector(-4, 1, 3, 5);

    EXPECT_NEAR(vector.length(), 8.06, 0.05);
}

TEST(getVectorLength, Test2){
    Vector vector(0, 0, 8, 7);

    EXPECT_NEAR(vector.length(), 10.63, 0.05);
}

TEST(getVectorLength, Test3){
    Vector vector(-5, 8, 4, 6);

    EXPECT_NEAR(vector.length(), 9.2, 0.05);
}

TEST(vectorNumberMultiply, Test1){
    Vector vector(3,4, 5, 8);

    EXPECT_EQ(vector * 5, Point(10, 20));
}

TEST(vectorNumberMultiply, Test2){
    Vector vector(6, 10, -2, 3);

    EXPECT_EQ(vector * 4, Point(-32, -28));
}

TEST(vectorVectorMult, Test1){
    Vector vector1(2, 4, 7, 10);
    Vector vector2(8, -5, 3, 1);

    EXPECT_EQ(vector1 * vector2, 11);
}

TEST(vectorVectorMult, Test2){
    Vector vector1(-2, 5, 10, 9);
    Vector vector2(2,3,7,8);

    EXPECT_EQ(vector1 * vector2, 80);
}

TEST(vectorAngle, Test1){
    Vector vector1(5,8, 3,5);
    Vector vector2(1,2,-7,9);

    EXPECT_NEAR(vector1.getAngle(vector2), -0.13, 0.1);
}

TEST(vectorAngle, Test2){
    Vector vector1(5, 15);
    Vector vector2(-10, 9);

    EXPECT_NEAR(vector1.getAngle(vector2), 0.399, 0.1);
}


TEST(vectorAdd, Test1){
    Vector vector1(1, 4);
    Vector vector2(-2, 8);

    EXPECT_EQ(vector1 + vector2, Point(-1, 12));
}

TEST(vectorAdd, Test2){
    Vector vector1(-20, 7);
    Vector vector2(3, 15);

    EXPECT_EQ(vector1 + vector2, Point(-17, 22));
}

TEST(vectorSub, Test1){
    Vector vector1(-3, 4);
    Vector vector2(11, 23);

    EXPECT_EQ(vector1 - vector2, Point(-14, -19));
}

TEST(vectorSub, Test2){
    Vector vector1(0, 0);
    Vector vector2(14, 29);

    EXPECT_EQ(vector1 - vector2,Point(-14,-29));
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}