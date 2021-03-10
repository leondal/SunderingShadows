// The spell research daemon
#define SRD "/daemon/spell_research"

// The directory where the wizard spell files are located.
#define SPELL_DIRECTORY "/cmds/wizard/"

// The officially recognized schools of magic here
#define SCHOOLS ({ "abjuration", "conjuration_summoning", \
"greater divination", "enchantment_charm", \
"invocation_evocation", "necromancy", "alteration" })

// Maximum proficency in any spell that can be gained through
// pure research
#define MAX_PROF 75

// Specialist research bonus.  Affects speed of research.
// 1 = standard 1.5 = 50% bonus for specialist
#define SPEC_RSRCH_BONUS 1.5

// Base intelligence used for determining the intelligence bonus
// for researchers
#define BASE_INT 15

// Number of points per point of intelligence over (or under)
// the base intelligence score to be added to the intelligence
// bonus.
#define INT_BONUS_MULTIPLIER 2

// Number of points per level to attain before being granted an
// answer about a spell element.  First element = arr[0], etc.
#define RSRCH_PT_LVLS ({ 1000, 4000, 9000, 16000, 25000, 36000, 49000, 64000, 81000 })

// Number of points per level to attain before being granted an
// answer about a spell element.  First element = arr[0], etc.
#define TRANSCRIBE_COST ({ 200, 400, 900, 1600, 2500, 3600, 4900, 6400, 8100 })

// Descriptive words or phrases used to define a spell search
// from scratch.
#define SEARCH_WORDS ({\
"no components",\
"components",\
"offensive",\
"defensive",\
"transport",\
"location",\
"area effect",\
"summoning",\
"information",\
"detection",\
"warding",\
"permanent",\
"fire",\
"earth",\
"water",\
"air",\
"ether",\
"imbue",\
"scrying",\
"mind control",\
"transformation" \
})

// Fake "magic words" that make up a chain of elements to
// be strung together to be encanted to discover a new spell.
#define ELEMENTS ({\
"xerzes",\
"harrnus",\
"rakkonus",\
"zazput",\
"puzid",\
"xaszi",\
"zintz",\
"ctalerub",\
"fugonius",\
"nieldred",\
"boonta",\
"crassus",\
"aaradnit",\
"cufabor",\
"soontar",\
"wastan",\
"mantage",\
"toolfa",\
"grenus",\
"curfi",\
"taynaz",\
"rayooz",\
"qwerty",\
"ylum",\
"lumberious",\
"garnad",\
"nroht",\
"natsirt",\
"latsyrc",\
"terrag",\
"irtev",\
"ocut",\
"livda",\
"ooter",\
"missik",\
"metib",\
"terab",\
"wodahs",\
"reggad",\
"fizzdorf",\
"rikknop",\
"skcusrakhsav" \
})
