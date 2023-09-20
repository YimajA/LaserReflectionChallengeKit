

#ifndef USER_INTERFACE_INCLUDED
#define USER_INTERFACE_INCLUDED

class UserInterface {
    private:

    // the value from the encoder that corresponds to mirror zero
    // this value may change if the user tries to spin the encoder
    // around too far, this should shift
    // the reference.
    static int encoderMirrorZero;

    // Similar to the above, but for the angles of the mirrors
    static int encoderMirrorAngleZero;

    // Used for when the user switches mirrors, it should be able to
    // grab the angle of the mirror the user switches to so that it
    // can update the encoderMirrorAngleZero appropriately
    static int mirrorAngles[6];

    // to know whether to allow selection of a given mirror
    static bool disabledMirrors[6];

    public:
    // the index of the mirror, from 0 to 5
    static int getMirrorSelected();

    // degrees
    static int getMirrorRotation();

    // of the currently selected mirror, only needed if the position changes
    // by some other means in code
    static void setMirrorAngle(int degrees);

    static bool isButtonPushed();

    static void setWaitingToStart(bool isWaitingToStart);

    static void setMirrorDisabled(int index, bool isDisabled);
};

#endif // USER_INTERFACE_INCLUDED