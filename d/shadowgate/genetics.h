#define AGES ({"child", "normal", "middle aged", "old", "venerable"})

#define AGE_CATS  (["child" : -10 - random(8), "normal" : random(30), "middle aged" : 60 + random(60), "old" : 100 + random(140),\
                    "venerable" : 250 + random(250)])

#define HEIGHTS ({"short", "average", "tall"})

#define HEIGHT_CATS (["short" : 1 + random(30), "average" : 31 + random(40), "tall" : 71 + random(30) ])

#define WEIGHT_CATS (["1" : (["display name" : "1 Scrawny", "value" : 50 + random(60), "choice" : "Scrawny",]),\
                      "2" : (["display name" : "2 ...", "value" : 60 + random(50), "choice" : "Between Scrawny and Average",]),\
                      "3" : (["display name" : "3 ...", "value" : 70 + random(45), "choice" : "Between Scrawny and Average",]),\
                      "4" : (["display name" : "4 Average", "value" : 90 + random(30), "choice" : "Average",]),\
                      "5" : (["display name" : "5 ...", "value" : 85 + random(50), "choice" : "Between Average and Heavy",]),\
                      "6" : (["display name" : "6 ...", "value" : 90 + random(50), "choice" : "Between Average and Heavy",]),\
                      "7" : (["display name" : "7 Heavy", "value" : 95 + random(60), "choice" : "Heavy"]), ])

#define MAXPOINTS 56 // 92 total points minus 36 starting points (6 per stat). -N, 10/10.

#define TESTCLASS ({})
#define TESTERS ({})
// stats in order: str, dex, con, int, wis, cha
#define STATS ({"strength","dexterity","constitution", "intelligence", "wisdom" ,"charisma"})

//([ max weight that will display these choices : ({choices})])
#define BODY_TYPES ([ 1 : ({"frail", "gaunt", "scrawny"}), 2 : ({"skinny", "slight", "lean"}), 3 : ({"slender", "slim", "thin"}),\
                      4 : ({"svelte", "average", "plump"}), 5 : ({"well-built", "hardy", "stocky"}), 6: ({"portly", "stout", "brawny"}),\
                      7 : ({"massive", "rotund", "heavy"}), ])


#define UNIQUE_HELP (["School Name" : "mage schools", "Fighting Style" : "styles", "Discipline Name" : "disciplines", "Warlock Heritage" : "warlock heritages"])

#define DONTSORT ({"age", "height", "body type"})

#define RESETTYPES ([ "age" : "age", "gender" : "gender", "height" : "height", "body type" : "body type", "weight" : "weight", "lineage" : "special", "parent lineage" : "special", \
                      "school name" : "unique", "fighting style" : "unique", "school" : "unique", "mage school" : "unique", "discipline" : "unique",\
                      "psion discipline" : "unique", "class" : "class", "discipline name" : "unique",\
                      "Character Class" : "class", "character class" : "class", "race" : "race", "Race" : "race", "Subrace" : "subrace", "subrace" : "subrace",\
                      "heritage" : "unique", "Heritage" : "unique", "Warlock Heritage" : "unique", "Stats" : "stats", "stats" : "stats", "strength": "stats",\
                      "constitution" : "stats", "wisdom" : "stats", "intelligence" : "stats", "dexterity" : "stats", "charisma" : "stats",\
                      "alignment" : "alignment", "deity" : "deity", "diety" : "deity", "hair" : "hair color", "hair color" : "hair color", "eye" : "eye color",\
                      "eye color" : "eye color", "parent" : "special"])

#define STEPVALUES (["class" : 1, "race" : 2, "special" : 3, "subrace" : 4, "stats" : 5, "hair color" : 6, "eye color" : 7, "height" : 8, "weight" : 9,\
                     "body type" : 10, "age" : 11, "alignment" : 12, "unique" : 13, "deity" : 14, "finalize" : 15])

#define RECOMMENDED_STATS (["fighter" : (["strength" : 18, "constitution" : 18, "dexterity" : 18, "wisdom" : 13, "intelligence" : 13, "charisma" : 12]),\
                            "mage" : (["strength" : 14, "constitution" : 18, "dexterity" : 14, "wisdom" : 15, "intelligence" : 18, "charisma" : 13]),\
                            "cleric" : (["strength" : 18, "wisdom" : 18, "constitution" : 18, "dexterity" : 12, "intelligence" : 13, "charisma" : 13]),\
                            "oracle" : (["charisma" : 18, "constitution" : 18, "intelligence" : 14, "dexterity" : 16, "strength" : 14, "wisdom" : 12]),\
                            "psywarrior" : (["intelligence" : 18, "strength" : 18, "constitution" : 18, "dexterity" : 14, "wisdom" : 12, "charisma" : 12]),\
                            "psion" : (["intelligence" : 18, "strength" : 14, "constitution" : 18, "dexterity" : 18, "wisdom" : 12, "charisma" : 12]),\
                            "druid" : (["strength" : 18, "wisdom" : 18, "constitution" : 18, "dexterity" : 12, "intelligence" : 13, "charisma" : 13]),\
                            "warlock" : (["charisma" : 18, "constitution" : 18, "strength" : 16, "dexterity" : 13, "intelligence" : 14, "wisdom" : 13]),\
                            "bard" : (["charisma" : 18, "constitution" : 18, "dexterity" : 18, "strength" : 14, "intelligence" : 12, "wisdom" : 12]),\
                            "inquisitor" : (["strength" : 18, "wisdom" : 18, "constitution" : 18, "dexterity" : 12, "intelligence" : 13, "charisma" : 13]),\
                            "sorcerer" : (["charisma" : 18, "constitution" : 18, "intelligence" : 14, "dexterity" : 16, "strength" : 14, "wisdom" : 12]),\
                            "barbarian" : (["strength" : 18, "constitution" : 18, "dexterity" : 16, "wisdom" : 14, "intelligence" : 13, "charisma" : 13]),\
                            "thief" : (["dexterity" : 18, "constitution" : 18, "strength" : 15, "intelligence" : 15, "wisdom" : 13, "charisma" : 13]),\
                            "paladin" : (["strength" : 18, "charisma" : 18, "wisdom" : 18, "constitution" : 16, "intelligence" : 11, "dexterity" : 11]),\
                            "ranger" : (["dexterity" : 18, "wisdom" : 16, "strength" : 16, "constitution" : 18, "intelligence" : 12, "charisma" : 12]),\
                            "monk" : (["dexterity" : 18, "wisdom" : 18, "constitution" : 16, "intelligence" : 12, "charisma" : 12, "strength" : 16]),\
                            "magus" : (["dexterity" : 18, "wisdom" : 14, "constitution" : 18, "intelligence" : 18, "charisma" : 10, "strength" : 14]),\
                            "cavalier" : (["strength" : 18, "charisma" : 18, "wisdom" : 18, "constitution" : 16, "intelligence" : 11, "dexterity" : 11]),])
