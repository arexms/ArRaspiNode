#include <gtest/gtest.h>
#include <Ar/Raspi/Node/Node.h>

TEST(Node, CheckStart)
{
    Ar::Raspi::Node::Node node;
    auto ret = node.start(23);
    EXPECT_TRUE(ret);
}