//
// Created by Tomi on 2019. 03. 04..
//
extern "C" {
#include "poker.h"
}
#include "gtest/gtest.h"

TEST(TestTesting, TestingTest){
    EXPECT_EQ(1, 1);
}

TEST(TestCard, StrToCard) {
    EXPECT_EQ(8, str_to_card("8D"));
}

TEST(TestCard, strToColor){
    EXPECT_STREQ("Diamonds", str_to_color("8D"));
}

TEST(TestCard, tenCard) {
    EXPECT_EQ(10, str_to_card("TD"));
}

TEST(TestCard, jackCard) {
    EXPECT_EQ(11, str_to_card("JD"));
}

TEST(TestCard, queenCard) {
    EXPECT_EQ(12, str_to_card("QD"));
}

TEST(TestCard, kingCard) {
    EXPECT_EQ(13, str_to_card("KD"));
}

TEST(TestCard, aceCard) {
    EXPECT_EQ(14, str_to_card("AD"));
}

TEST(TestCard, cardStruct) {
    card_t card = str_to_card_t("AD");
    EXPECT_EQ(14, card.value);
}

/*
TEST(TestPoker, StrToSet) {
    card_t set[5] = str_to_set("...");
    EXPECT_EQ()
}*/

/*TEST(TestPoker, IsBetter) {
    EXPECT_EQ(1, is_better_set("AD KD QD JD XD", "2D 3D 4D 5D 6D"));
    EXPECT_EQ(1, is_better_set("6D KD QD JD AD", "8D 3D 4D 5D 7D"));
}*/