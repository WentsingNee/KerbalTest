
add_kerbal_test_target(test.algorithm.set.includes                        ./set/includes.test.cpp)
add_kerbal_test_target(test.algorithm.set.set_difference                  ./set/set_difference.test.cpp)
add_kerbal_test_target(test.algorithm.set.set_intersection                ./set/set_intersection.test.cpp)
add_kerbal_test_target(test.algorithm.set.set_symmetric_difference        ./set/set_symmetric_difference.test.cpp)
add_kerbal_test_target(test.algorithm.set.set_union                       ./set/set_union.test.cpp)

set(test_targets ${test_targets} PARENT_SCOPE)
