#include <gtest/gtest.h>
#include "../../src/shape/shape.hpp"

TEST(TestArea, AreaTest1){
    Shape shape;
    shape.addPoint(1,1);
    shape.addPoint(2, 4);
    shape.addPoint(5, 3);
    EXPECT_EQ(shape.getArea(), 5);
}

TEST(TestArea, AreaTest2){
    Shape shape;
    shape.addPoint(-2, -1);
    shape.addPoint(-1, 1);
    shape.addPoint(1, 2);
    shape.addPoint(3, 1);
    shape.addPoint(2, -2);
    EXPECT_EQ(shape.getArea(), 12.5);
}

TEST(TestArea, AreaTest3){
    Shape shape;
    shape.addPoint(1, 2);
    shape.addPoint(2, 5);
    shape.addPoint(3, 3);
    shape.addPoint(3, 1);
    EXPECT_EQ(shape.getArea(), 4.5);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}