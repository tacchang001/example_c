// https://stackoverflow.com/questions/31989040/can-gmock-be-used-for-stubbing-c-functions

#include "IBar.h"

#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace ::testing;
using ::testing::Return;

class BCM2835_MOCK {
public:
    virtual ~BCM2835_MOCK() {}

    // mock methods
    MOCK_METHOD0(bcm2835_init, int());

    MOCK_METHOD2(bcm2835_gpio_fsel, void(uint8_t, uint8_t));
};

class TestFixture : public ::testing::Test {
public:
    TestFixture() {
        _bcm2835Mock.reset(new ::testing::NiceMock<BCM2835_MOCK>());
    }

    ~TestFixture() {
        _bcm2835Mock.reset();
    }

    virtual void SetUp() {}

    virtual void TearDown() {}

    // pointer for accessing mocked library
    static std::unique_ptr<BCM2835_MOCK> _bcm2835Mock;
};

// fake lib functions
int bcm2835_init() {
    return TestFixture::_bcm2835Mock->bcm2835_init();
}

void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode) {
    TestFixture::_bcm2835Mock->bcm2835_gpio_fsel(pin, mode);
}

// create unit testing class for BCM2835 from TestFixture
class BCM2835LibUnitTest : public TestFixture {
public:
    BCM2835LibUnitTest() {
        // here you can put some initializations
    }
};

TEST_F(BCM2835LibUnitTest, inits) {
    EXPECT_CALL(*_bcm2835Mock, bcm2835_init()).Times(1).WillOnce(Return(1));

    EXPECT_EQ(1, inits()) << "init must return 1";
}

TEST_F(BCM2835LibUnitTest, pinModeTest) {

    EXPECT_CALL(*_bcm2835Mock, bcm2835_gpio_fsel((uint8_t) RPI_V2_GPIO_P1_18, (uint8_t) BCM2835_GPIO_FSEL_OUTP
    )
    )
            .Times(1);

    pinMode((uint8_t) RPI_V2_GPIO_P1_18, (uint8_t) BCM2835_GPIO_FSEL_OUTP);
}