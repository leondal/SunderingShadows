/* the default adverb for the cmd is overridden by an environment
   variable */
#define ENVIRONMENT 0x0001

/* use the optional verb instead of the query_verb() one */
#define OVERB 0x0002

/* apostrophize the target's name */
#define APOSTROPHE 0x0004

/* always use the adverb */
#define FORCEADVERB 0x0008

/* definitions for non-standard formats */
#define FORMAT0 0x0100
#define FORMAT1 0x0200
#define FORMAT2 0x0400
#define FORMAT (FORMAT0|FORMAT1|FORMAT2)

/* special variables used by the messages */
#define OBJECTIVE 0x0010
#define POSSESSIVE 0x0020
#define SUBJECTIVE 0x0040
#define VARIABLE (OBJECTIVE|POSSESSIVE|SUBJECTIVE)
