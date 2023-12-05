#include <gtest/gtest.h>
#include <bitset>

TEST(BasicTests, SanityTest) {
    EXPECT_EQ(4, 4);
}

TEST(BasicTests, BitSetBasicTest) {
    std::bitset<3> y(19);
    std::bitset<4> x(7);
    std::bitset<6> v(14);
    EXPECT_EQ(x, 0b0111);
    EXPECT_EQ(x.to_ulong(), 0b0111);
    EXPECT_EQ(x.to_ulong(), 0b000000111);
    EXPECT_EQ(x.to_ulong(), 7);
    EXPECT_EQ(x.to_ulong(), 0x7);

    EXPECT_NE(y.to_ulong(), 0b10011);
    EXPECT_EQ(y.to_ulong(), 0b011);
    EXPECT_EQ(y.to_ulong(), 3);

    EXPECT_EQ(v.to_ulong(), 0xe);
}

TEST(BasicTests, BitSetLongTest) {
    std::bitset<32> y(4294967295);
    std::bitset<32> x(429496729);
    std::bitset<32> v(4294967296);
    EXPECT_EQ(x.to_ulong(), 0b11001100110011001100110011001);
    EXPECT_EQ(x.to_ulong(), 429496729);
    EXPECT_EQ(y.to_ulong(), 4294967295);
    EXPECT_EQ(y.to_ulong(), 0b11111111111111111111111111111111);
    EXPECT_NE(v.to_ulong(), 4294967296);
    EXPECT_NE(v.to_ulong(), 0b100000000000000000000000000000000);
}
