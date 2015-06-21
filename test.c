#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "minifloat.hh"


TEST_CASE( "Test values", "[minifloat]") {
    std::map<unsigned char, int> positive_values = {
     {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
     {6, 6}, {7, 7}, {8, 8}, {9, 9}, {10, 10}, {11, 11}, {12, 12}, {13, 13},
     {14, 14}, {15, 15}, {16, 16}, {17, 18}, {18, 20}, {19, 22}, {20, 24},
     {21, 26}, {22, 28}, {23, 30}, {24, 32}, {25, 36}, {26, 40}, {27, 44},
     {28, 48}, {29, 52}, {30, 56}, {31, 60}, {32, 64}, {33, 72}, {34, 80},
     {35, 88}, {36, 96}, {37, 104}, {38, 112}, {39, 120}, {40, 128}, {41, 144},
     {42, 160}, {43, 176}, {44, 192}, {45, 208}, {46, 224}, {47, 240},
     {48, 256}, {49, 288}, {50, 320}, {51, 352}, {52, 384}, {53, 416},
     {54, 448}, {55, 480}, {56, 512}, {57, 576}, {58, 640}, {59, 704},
     {60, 768}, {61, 832}, {62, 896}, {63, 960}, {64, 1024}, {65, 1152},
     {66, 1280}, {67, 1408}, {68, 1536}, {69, 1664}, {70, 1792}, {71, 1920},
     {72, 2048}, {73, 2304}, {74, 2560}, {75, 2816}, {76, 3072}, {77, 3328},
     {78, 3584}, {79, 3840}, {80, 4096}, {81, 4608}, {82, 5120}, {83, 5632},
     {84, 6144}, {85, 6656}, {86, 7168}, {87, 7680}, {88, 8192}, {89, 9216},
     {90, 10240}, {91, 11264}, {92, 12288}, {93, 13312}, {94, 14336},
     {95, 15360}, {96, 16384}, {97, 18432}, {98, 20480}, {99, 22528},
     {100, 24576}, {101, 26624}, {102, 28672}, {103, 30720}, {104, 32768},
     {105, 36864}, {106, 40960}, {107, 45056}, {108, 49152}, {109, 53248},
     {110, 57344}, {111, 61440}, {112, 65536}, {113, 73728}, {114, 81920},
     {115, 90112}, {116, 98304}, {117, 106496}, {118, 114688}, {119, 122880}};

    std::map<unsigned char, minifloat> infinity_values = {
     {120, std::numeric_limits<minifloat>::infinity()},
     {248, -std::numeric_limits<minifloat>::infinity()}};

    std::map<unsigned char, int> negative_values = {
     {128, -0}, {129, -1}, {130, -2}, {131, -3}, {132, -4}, {133, -5},
     {134, -6}, {135, -7}, {136, -8}, {137, -9}, {138, -10}, {139, -11},
     {140, -12}, {141, -13}, {142, -14}, {143, -15}, {144, -16}, {145, -18},
     {146, -20}, {147, -22}, {148, -24}, {149, -26}, {150, -28}, {151, -30},
     {152, -32}, {153, -36}, {154, -40}, {155, -44}, {156, -48}, {157, -52},
     {158, -56}, {159, -60}, {160, -64}, {161, -72}, {162, -80}, {163, -88},
     {164, -96}, {165, -104}, {166, -112}, {167, -120}, {168, -128},
     {169, -144}, {170, -160}, {171, -176}, {172, -192}, {173, -208},
     {174, -224}, {175, -240}, {176, -256}, {177, -288}, {178, -320},
     {179, -352}, {180, -384}, {181, -416}, {182, -448}, {183, -480},
     {184, -512}, {185, -576}, {186, -640}, {187, -704}, {188, -768},
     {189, -832}, {190, -896}, {191, -960}, {192, -1024}, {193, -1152},
     {194, -1280}, {195, -1408}, {196, -1536}, {197, -1664}, {198, -1792},
     {199, -1920}, {200, -2048}, {201, -2304}, {202, -2560}, {203, -2816},
     {204, -3072}, {205, -3328}, {206, -3584}, {207, -3840}, {208, -4096},
     {209, -4608}, {210, -5120}, {211, -5632}, {212, -6144}, {213, -6656},
     {214, -7168}, {215, -7680}, {216, -8192}, {217, -9216}, {218, -10240},
     {219, -11264}, {220, -12288}, {221, -13312}, {222, -14336}, {223, -15360},
     {224, -16384}, {225, -18432}, {226, -20480}, {227, -22528}, {228, -24576},
     {229, -26624}, {230, -28672}, {231, -30720}, {232, -32768}, {233, -36864},
     {234, -40960}, {235, -45056}, {236, -49152}, {237, -53248}, {238, -57344},
     {239, -61440}, {240, -65536}, {241, -73728}, {242, -81920}, {243, -90112}, 
     {244, -98304}, {245, -106496}, {246, -114688}, {247, -122880}};

    std::map<unsigned char, minifloat> nan_values = {
     {121, std::numeric_limits<minifloat>::quiet_NaN()},
     {122, std::numeric_limits<minifloat>::quiet_NaN()},
     {123, std::numeric_limits<minifloat>::quiet_NaN()},
     {124, std::numeric_limits<minifloat>::quiet_NaN()},
     {125, std::numeric_limits<minifloat>::quiet_NaN()},
     {126, std::numeric_limits<minifloat>::quiet_NaN()},
     {127, std::numeric_limits<minifloat>::quiet_NaN()},
     {249, std::numeric_limits<minifloat>::quiet_NaN()},
     {250, std::numeric_limits<minifloat>::quiet_NaN()},
     {251, std::numeric_limits<minifloat>::quiet_NaN()},
     {252, std::numeric_limits<minifloat>::quiet_NaN()},
     {253, std::numeric_limits<minifloat>::quiet_NaN()},
     {254, std::numeric_limits<minifloat>::quiet_NaN()},
     {255, std::numeric_limits<minifloat>::quiet_NaN()}};

    SECTION( "Positive numbers" ) {
        for(auto const &it : positive_values) {
            unsigned char mantissa, exponent, sign, whole;
            std::cerr << (int)it.first << ":" << it.second << std::endl;

            minifloat v = it.second;
            whole = v.bits();
            mantissa = whole & 0b00000111;
            exponent = whole & 0b01111000;
            sign = whole >> 7;

            REQUIRE(mantissa == (it.first & 0b00000111));
            REQUIRE(exponent == (it.first & 0b01111000));
            REQUIRE(sign == 0);

            minifloat u(it.second);
            whole = u.bits();
            mantissa = whole & 0b00000111;
            exponent = whole & 0b01111000;
            sign = whole >> 7;

            REQUIRE(mantissa == (it.first & 0b00000111));
            REQUIRE(exponent == (it.first & 0b01111000));
            REQUIRE(sign == 0);
        }
    }

    SECTION( "Negative numbers" ) {
        for(auto const &it : negative_values) {
            unsigned char mantissa, exponent, sign, whole;
            std::cerr << (int)it.first << ":" << it.second << std::endl;

            minifloat v = it.second;
            whole = v.bits();
            mantissa = whole & 0b00000111;
            exponent = whole & 0b01111000;
            sign = whole >> 7;

            REQUIRE(mantissa == (it.first & 0b00000111));
            REQUIRE(exponent == (it.first & 0b01111000));
            REQUIRE(sign == 1);

            minifloat u(it.second);
            whole = u.bits();
            mantissa = whole & 0b00000111;
            exponent = whole & 0b01111000;
            sign = whole >> 7;

            REQUIRE(mantissa == (it.first & 0b00000111));
            REQUIRE(exponent == (it.first & 0b01111000));
            REQUIRE(sign == 1);
        }
    }

    /*
    SECTION( "Infinity numbers" ) {
        for(auto const &it : negative_values) {
            minifloat v = it.second;

            minifloat u(it.second);
        }
    }

    SECTION( "NaN numbers" ) {
        for(auto const &it : negative_values) {
            minifloat v = it.second;

            minifloat u(it.second);
        }
    }
    */
}
