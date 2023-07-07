#include "../../utilities/items/DOF.h"
#include <gtest/gtest.h>

TEST(DOFUpdate, FxOnly)
{
	double Fx = 1.0;

 	DOF dof;
    dof.update(Fx);

    const auto expected = Fx;
    const auto actual = dof.get_Fx();

    ASSERT_EQ(expected, actual);
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}