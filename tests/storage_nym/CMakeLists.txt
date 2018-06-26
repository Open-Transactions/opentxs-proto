set(name unittests-opentxs-storage-nym)

set(cxx-sources
        main.cpp
        Test_StorageNym.cpp
        )

add_executable(${name} ${cxx-sources}  $<TARGET_OBJECTS:opentxs-proto> $<TARGET_OBJECTS:opentxs-verify>)
set_target_properties(${name} PROPERTIES ENABLE_EXPORTS 1 RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/tests)
target_link_libraries(${name} ${PROTOBUF_LITE_LIBRARIES} ${GTEST_LIBRARY})
add_test(${name} ${PROJECT_BINARY_DIR}/tests/${name} --gtest_output=xml:gtestresults.xml)
