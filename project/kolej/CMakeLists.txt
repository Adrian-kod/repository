cmake_minimum_required(VERSION 3.10)
project(kolej)



find_package(Boost REQUIRED COMPONENTS date_time unit_test_framework)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_FILES
        src/Client.cpp
        include/model/Client.h
        include/typedefs.h
        src/ClientManager.cpp
        include/model/ClientManager.h
        include/model/DiscountRate.h
        src/DiscountRate.cpp
        include/model/ClientRepository.h
        src/ClientRepository.cpp
        include/model/ElderlyDiscount.h
        src/ElderlyDiscount.cpp
        include/model/NormalDiscount.h
        src/NormalDiscount.cpp
        include/model/Route.h
        src/Route.cpp
        include/model/Schedule.h
        src/Schedule.cpp
        include/model/WorkerDiscount.h
        src/WorkerDiscount.cpp
        include/model/Train.h
        src/Train.cpp
        include/model/PassengerTrain.h
        src/PassengerTrain.cpp
        include/model/GoodsTrain.h
        src/GoodsTrain.cpp
        include/model/LargeGoodsTrain.h
        src/LargeGoodsTrain.cpp
        include/model/LuxuryGoodsTrain.h
        src/LuxuryGoodsTrain.cpp
)
add_library(kolej ${SOURCE_FILES})

target_include_directories(kolej PUBLIC include ${Boost_INCLUDE_DIRS})

enable_testing()

set(SOURCE_TEST_HUMAN_FILES
        test/ClientTest.cpp
        test/RouteTest.cpp
        test/ScheduleTest.cpp
        test/TrainTest.cpp
        test/TicketTest.cpp
        test/TicketSystemTest.cpp
        src/StudentDiscount.cpp
        src/DiscountRate.cpp
        include/typedefs.h

)
add_executable(Tests ${SOURCE_TEST_HUMAN_FILES})

target_link_libraries(Tests PRIVATE
        kolej
        ${Boost_LIBRARIES})

add_test(TestKolei Tests
        --report_level=detailed
        --log_level=all
        --color_output=yes
        --show_progress=true
)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})