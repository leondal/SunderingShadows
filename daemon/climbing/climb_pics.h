#define JUG 1
#define LEDGE 2
#define CRIMP 3
#define PINCH 4
#define FLAKE 5
#define POCKET 6
#define SLOPER 7
#define HORN 8
#define ROPE 9

#define HANDHOLDS ([\
"a": "%^BOLD%^%^GREEN%^_%^BOLD%^%^WHITE%^",\
"b": "%^RESET%^%^GREEN%^_%^BOLD%^%^WHITE%^",\
"c": "%^RESET%^%^ORANGE%^_%^BOLD%^%^WHITE%^",\
"d": "%^RESET%^%^RED%^_%^BOLD%^%^WHITE%^",\
"e": "%^BOLD%^%^RED%^_%^BOLD%^%^WHITE%^",\
"f": "%^BOLD%^%^GREEN%^/%^BOLD%^%^WHITE%^",\
"g": "%^RESET%^%^GREEN%^/%^BOLD%^%^WHITE%^",\
"h": "%^RESET%^%^ORANGE%^/%^BOLD%^%^WHITE%^",\
"i": "%^RESET%^%^RED%^/%^BOLD%^%^WHITE%^",\
"j": "%^BOLD%^%^RED%^/%^BOLD%^%^WHITE%^",\
"k": "%^BOLD%^%^GREEN%^\\%^BOLD%^%^WHITE%^",\
"l": "%^RESET%^%^GREEN%^\\%^BOLD%^%^WHITE%^",\
"m": "%^RESET%^%^ORANGE%^\\%^BOLD%^%^WHITE%^",\
"n": "%^RESET%^%^RED%^\\%^BOLD%^%^WHITE%^",\
"o": "%^BOLD%^%^RED%^\\%^BOLD%^%^WHITE%^",\
"p": "%^BOLD%^%^GREEN%^|%^BOLD%^%^WHITE%^",\
"q": "%^RESET%^%^GREEN%^|%^BOLD%^%^WHITE%^",\
"r": "%^RESET%^%^ORANGE%^|%^BOLD%^%^WHITE%^",\
"s": "%^RESET%^%^RED%^|%^BOLD%^%^WHITE%^",\
"t": "%^BOLD%^%^RED%^|%^BOLD%^%^WHITE%^",\
"u": "%^BOLD%^%^GREEN%^.%^BOLD%^%^WHITE%^",\
"v": "%^RESET%^%^GREEN%^.%^BOLD%^%^WHITE%^",\
"w": "%^RESET%^%^ORANGE%^.%^BOLD%^%^WHITE%^",\
"x": "%^RESET%^%^RED%^.%^BOLD%^%^WHITE%^",\
"y": "%^BOLD%^%^RED%^.%^BOLD%^%^WHITE%^",\
"z": "%^BOLD%^%^GREEN%^@%^BOLD%^%^WHITE%^",\
"1": "%^RESET%^%^GREEN%^@%^BOLD%^%^WHITE%^",\
"2": "%^RESET%^%^ORANGE%^@%^BOLD%^%^WHITE%^",\
"3": "%^RESET%^%^RED%^@%^BOLD%^%^WHITE%^",\
"4": "%^BOLD%^%^RED%^@%^BOLD%^%^WHITE%^",\
"5": "%^BOLD%^%^GREEN%^^%^BOLD%^%^WHITE%^",\
"6": "%^RESET%^%^GREEN%^^%^BOLD%^%^WHITE%^",\
"7": "%^RESET%^%^ORANGE%^^%^BOLD%^%^WHITE%^",\
"8": "%^RESET%^%^RED%^^%^BOLD%^%^WHITE%^",\
"9": "%^BOLD%^%^RED%^^%^BOLD%^%^WHITE%^",\
"~": "%^BOLD%^%^WHITE%^w%^BOLD%^%^WHITE%^",\
"#": "%^BOLD%^%^WHITE%^r%^BOLD%^%^WHITE%^",\
"@": "%^BOLD%^%^WHITE%^7%^BOLD%^%^WHITE%^",\
"*": " %^BOLD%^%^WHITE%^"\
])

#define COLOURS ([ "r": "%^RESET%^%^RED%^", "R": "%^BOLD%^%^RED%^", "o" : "%^RESET%^%^ORANGE%^", "O": "%^BOLD%^%^ORANGE%^", "c": "%^RESET%^%^CYAN%^", "C" : "%^BOLD%^%^CYAN%^", "b": "%^RESET%^%^BLUE%^", "B": "%^BOLD%^%^BLUE%^", "m": "%^RESET%^%^MAGENTA%^", "M": "%^BOLD%^%^MAGENTA%^", "w" : "%^RESET%^%^WHITE%^", "W": "%^BOLD%^%^WHITE%^", "d": "%^RESET%^%^BLACK%^", "D": "%^BOLD%^%^BLACK%^", "P": "%^RESET%^"]) 

#define BG_COLS ([ "r": "%^B_RED%^", "o" : "%^B_ORANGE%^", "c": "%^B_CYAN%^", "b": "%^B_BLUE%^", "m": "%^B_MAGENTA%^", "w" : "%^B_WHITE%^",  "d": "%^B_BLACK%^"]) 

#define MED_BODY ({"          ","          ","    (*)   ","    |~|   ","    |*|   ","          ","          ","          "  })

#define L_ARM_3 ({"  w","  |","  |","   ","   ","   "})
#define L_ARM_11 ({"  ",".  "," \\_","   ","   ","   "})
#define L_ARM_12 ({"   "," , "," \\_","   ","   ","   "})
#define L_ARM_13 ({"   ","  r","  \\","   ","   ","   "})
#define L_ARM_14 ({"   ","  /^","  \\","   ","   "})
#define L_ARM_15 ({"   ","   /^","  |","   ","   "})
#define L_ARM_21 ({"   ","   ",".  "," \\-","   ","   "})
#define L_ARM_22 ({"   ","   "," r "," \\/","   ","   "})
#define L_ARM_23 ({"   ","   ","  r","  '","   ","   "})
#define L_ARM_24 ({"   ","  _","  \\","   ","   "})
#define L_ARM_25 ({"   ","  _","  \\","   ","   "})
#define L_ARM_30 ({"   ","   ","   ",">--","   "})
#define L_ARM_31 ({"   ","   ",".  "," \\/","   ","   "})
#define L_ARM_32 ({"   ","   "," . "," |/","   ","   "})
#define L_ARM_33 ({"   ","   ","  ,"," |/","   ","   "})
#define L_ARM_34 ({"   ","   ","  _"," '-","   "})
#define L_ARM_35 ({"   ","   ","  _"," '-","   "})
#define L_ARM_41 ({"   ","   ","  _"," / ","'  ","   "})
#define L_ARM_42 ({"   ","   ","  _"," / "," ^ ","   "})
#define L_ARM_43 ({"   ","   ","  _","  \\","  ^","   "})
#define L_ARM_44 ({"   ","   ","  _","  \\","   "})
#define L_ARM_45 ({"   ","   ","  _","  \\","   "})
#define L_ARM_51 ({"   ","   ","   ","  /"," / ","^  "})
#define L_ARM_52 ({"   ","   ","   ","  /"," / "," ^ "})
#define L_ARM_53 ({"   ","   ","   ","  /","  |","  ^"})
#define L_ARM_54 ({"   ","   ","   ","  |","  \\"})

#define R_ARM_1 ({" w  "," |  "," |  ","    ","    "})
#define R_ARM_2 ({"  w  ","  |  ","  |  ","     ","     "})
#define R_ARM_10 ({"    ","^\\  ","  | ","    ","    "})
#define R_ARM_11 ({"     "," ^\\  ","  /  ","     ","     "})
#define R_ARM_12 ({"     ","  ?  ","  /  ","     ","     "})
#define R_ARM_13 ({"     ","   .  ","  _/  ","     ","     "})
#define R_ARM_14 ({"     ","    ,  ","  _/  ","     ","     "})
#define R_ARM_20 ({"     ","  _  ","  /  ","     ","     "})
#define R_ARM_21 ({"     ","  _  ","  /  ","     ","     "})
#define R_ARM_22 ({"     ","     ","  7   ","     ","     "})
#define R_ARM_23 ({"     ","     ","   7 ","  \\/ ","     "})
#define R_ARM_24 ({"     ","     ","    .","  -/ ","     "})
#define R_ARM_30 ({"     ","     ","  _   ","  -' ","     "})
#define R_ARM_31 ({"     ","     ","  _   ","  -' ","     "})
#define R_ARM_32 ({"     ","     ","  .  ","  \\| ","     "})
#define R_ARM_33 ({"     ","     ","   , ","  \\| ","     "})
#define R_ARM_34 ({"     ","     ","     ","  \\/`","     "})
#define R_ARM_35 ({"     ","     ","     ","  --<","     "})
#define R_ARM_40 ({"     ","     ","  _  ","  /  ","     "})
#define R_ARM_41 ({"     ","     ","  _  ","  /  ","     "})
#define R_ARM_42 ({"     ","     ","  _   ","  /  ","  ^  "})
#define R_ARM_43 ({"     ","     ","  _  ","   \\ ","   ^ "})
#define R_ARM_44 ({"     ","     ","  _  ","   \\ ","    '"})
#define R_ARM_50 ({"     ","     ","     ","  |  ","  /  "})
#define R_ARM_51 ({"     ","     ","     ","  |  ","  /  "})
#define R_ARM_52 ({"     ","     ","     ","  \\  ","  |  ", "  ^  "})
#define R_ARM_53 ({"     ","     ","     ","  \\  ","   \\ ","   ^ "})
#define R_ARM_54 ({"     ","     ","     ","  \\  ","   \\ ","    ^"})

#define L_LEG_0 ({"     ","./\\ ","    ","    ","    "})
#define L_LEG_1 ({"     "," ./\\","    ","    ","    "})
#define L_LEG_2 ({"     ","  |\\","    ","    ","    "})
#define L_LEG_3 ({"  _  ","  \\ ","   '","    ","    "})
#define L_LEG_4 ({"  .  ","   \\","    '","     ","    "})
#define L_LEG_13 ({"     ","  _ ","  \\.","    ","    "})
#define L_LEG_10 ({"     ","  _ ","./  ","    ","    "})
#define L_LEG_11 ({"     ","  _ "," J  ","    ","    "})
#define L_LEG_12 ({"     ","  , ","  | ","    ","    "})
#define L_LEG_13 ({"     ","  _ ","  \\,","    ","    "})
#define L_LEG_14 ({"     ","  .  ","   \\.","    ","     "})
#define L_LEG_21 ({"     ","    ","  / "," /  ","     "})
#define L_LEG_22 ({"     ","    ","  / ","  | ","    "})
#define L_LEG_23 ({"     ","    ","   /","   \\","    "})
#define L_LEG_24 ({"     ","    ","   \\.","    |","     "})
#define L_LEG_33 ({"     ","    ","   | ","   | ","   ' "})

#define R_LEG_0 ({"     ","./   ","     ","     ","    "})
#define R_LEG_1 ({"   . ","  /  "," '   ","     ","    "})
#define R_LEG_2 ({"   _ ","  // ","  '  ","     ","     "})
#define R_LEG_3 ({"     ","  /| ","     ","     ","     "})
#define R_LEG_4 ({"     ","  /\\,","     ","     ","     "})
#define R_LEG_5 ({"     ","   /\\,","     ","     ","     "})

#define R_LEG_10 ({"     ","     "," ./  ","     ","     "}) 

#define R_LEG_11 ({"     ","   . "," ./  ","     ","     "})
#define R_LEG_12 ({"     ","   _ ","  ./ ","     ","     "})
#define R_LEG_13 ({"     ","   . ","   | ","     ","     "})
#define R_LEG_14 ({"     ","   _ ","    L","     ","     "})
#define R_LEG_15 ({"     ","   _ ","    \\.","     ","     "})

#define R_LEG_20 ({"     ","    "," ./  "," |   ","     "})

#define R_LEG_21 ({"     ","     "," ./  "," |   ","     "})
#define R_LEG_22 ({"     ","     ","  \\  ","  /  ","     "})
#define R_LEG_23 ({"     ","     ","   \\ ","   | ","     "})
#define R_LEG_24 ({"     ","     ","   \\ ","    \\","     "})

#define R_LEG_31 ({"     ","     ","  |  ","  |  ","  '  "})

#define R_LEG_32 ({"     ","     ","  |  ","  |  ","  '  "})

#define DANGLING_LH ({"   w     ","   |     ","   |()   ","  /  \\  "," /  / \\ ","/ \\/   ^","| |     ","  |     "})
#define DANGLING_RH ({"         ","         ","   ()    ","   / \\   ","  /\\  \\  "," /  \\/ \\ ","^    | | ","     |   "})
#define TRIPPED ({"             ","             ","             ","             ","             ", "  .     ,    ","    \\___|  _ "," .__|____|(_)"})

#define SWING_RIGHT ({"(_)  ","| |--","|_|  ","  \\\\  ","   \\\\."})
#define SWING_LEFT ({"  (_)","--| |","  |_|","  // ",".//  "}) 