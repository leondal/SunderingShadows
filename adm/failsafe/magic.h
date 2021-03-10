// Magic Header File
// Thorn@ShadowGate
// IMPORTANT balance variable definitions for magic and spells
// are here, so that they can be changed without recoding numerous
// files.

// The amount of seconds, which will be multiplied by spell level
// that it takes to cast a spell.  It is the casting round length
#define EFFECT_DELAY 1

// Defines the length of a standard combat round for some purposes
#define ROUND_LENGTH 5

// Where all wizard spell files are kept.
#define SPELL_DIR "/cmds/wizard/"

// Where all objects created by spells are kept
#define SPELL_OBJ_DIR "/d/magic/etc/"

// Where the spell book and components bag are kept.  Very important
// directory
#define MAGIC_DIR "/d/magic/"

// How much time in seconds per level it takes to memorize a spell.
#define MEMORIZE_DELAY 3

//Memorization failures   Grendel
#define MEM_OK 1
#define TOO_STUPID 2
#define TOO_MANY 3
#define SPELL_RESTRICTED 4
#define NOT_WISE 5
#define NOT_SMART 6
//NOT_SMART for psions ~Circe~ 7/14/05