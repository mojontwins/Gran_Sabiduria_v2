// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// Precalculated stuff

const unsigned char attrs_adds [] = { 0xc0, 0xc8, 0xd0, 0xd8, 0xe0, 0xe8, 0xf0, 0xf8 };

// Directions are
// LEFT DOWNLEFT DOWN DOWNRIGHT RIGHT UPRIGHT UP UPLEFT
// 0    1        2    3         4     5       6  7
const signed char endx [] = {-1, -1, 0, 1, 1, 1, 0, -1};
const signed char endy [] = {0, 1, 1, 1, 0, -1, -1, -1};

