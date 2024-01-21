#include <gtest/gtest.h>
#include "../../src/time/time.hpp"

TEST(getAllSeconds, Test1){
    Time time(3.5, 23, 68);

    EXPECT_EQ(time.getAllSeconds(), 14048);
}

TEST(getAllSeconds, Test2){
    Time time(36.7, 567, 11);

    EXPECT_EQ(time.getAllSeconds(), 166151);
}

TEST(convertToMinutes, Test1){
    Time time(12, 45.6, 635);

    time.convertToMinutes();

    EXPECT_NEAR(time.getMinutes(), 776.1833333, 0.01);
}

TEST(convertToMinutes, Test2){
    Time time(10.5, 16.8, 5678);

    time.convertToMinutes();

    EXPECT_NEAR(time.getMinutes(), 741.4333333, 0.01);
}

TEST(convertToHours, Test1){
    Time time(10, 56.8, 123);

    time.convertToHours();

    EXPECT_NEAR(time.getHours(), 10.9808333, 0.01);
}

TEST(convertToHours, Test2){
    Time time(19, 235, 145);

    time.convertToHours();

    EXPECT_NEAR(time.getHours(), 22.9569444, 0.01);
}

TEST(convertToSeconds, Test1){
    Time time(0, 45, 67);

    time.convertToSeconds();

    EXPECT_EQ(time.getSeconds(), 2767);
}

TEST(convertToSeconds, Test2){
    Time time(23, 67, 123);

    time.convertToSeconds();

    EXPECT_EQ(time.getSeconds(), 86943);
}


TEST(convertToString, Test1){
    Time time(23, 67, 89);

    EXPECT_EQ(time.getString(), "23:67:89");
}

TEST(convertToString, Test2){
    Time time(23.6, 68, 11);

    EXPECT_EQ(time.getString(), "23:68:11");
}

TEST(addHours, Test1){
    Time time(0, 11, 456);

    time.addHours(11.33);

    EXPECT_EQ(time.getHours(), 11.33);
}

TEST(addMinutes, Test1){
    Time time(12, 45, 667);

    time.addMinutes(15.4);

    EXPECT_EQ(time.getMinutes(), 60.4);
}

TEST(addSeconds, Test1){
    Time time(6, 78, 123);

    time.addSeconds(15);

    EXPECT_EQ(time.getSeconds(), 138);
}

TEST(timeAdd, Test1){
    Time time1(1, 4, 56);
    Time time2(6, 89, 10);

    EXPECT_EQ(time1 + time2, Time(7, 93, 66));
}

TEST(timeAdd, Test2){
    Time time1(12, 45, 11);
    Time time2(6,7,8);

    EXPECT_EQ(time1 + time2, Time(18, 52, 19));
}

TEST(timeSub, Test1){
    Time time1(12, 67, 11);
    Time time2(4, 23, 8);

    EXPECT_EQ(time1 - time2, Time(8, 44, 3));
}

TEST(timeSub, Test2){
    Time time1(56, 12, 34);
    Time time2(34, 5, 10);

    EXPECT_EQ(time1 - time2, Time(22, 7, 24));
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}