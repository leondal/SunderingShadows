#define MATERIAL_PROPS ({ "density", "hardness" })

#define MATERIAL_TYPES ({ "fluid", "stone", "metal", "wood", "crystal", "glass", "leather", "cloth" })

#define CLOTH_TYPES ({ "burlap", "wool", "silk", "homespun", "cotton", "linen", "velvet", "satin", "brocade", "suede", "lace", "chiffon", "crepe", "felt", "flannel", "broadcloth", "muslin", "tweed", "gauze", "taffeta", "lame", "hemp" })

#define WOOD_TYPES ({ "pine", "birch", "ash", "walnut", "cypress", "oak", "butternut", "chestnut", "cherry", "mahogany", "hickory", "maple", "teak", "poplar", "alder", "duskwood", "rosewood", "elm", "cedar", "redwood", "boxwood", "ebony", "hazelnut", "willow", "spruce", "shadowtop", "silverbark", "beech", "blueleaf" })

#define METAL_TYPES ({ "titanium", "iron", "steel", "bronze", "copper", "mithril", "gold", "platinum", "electrum", "adamantium", "silver", "darksteel", "fever iron", "arandur", "cold iron", "dlaran", "palladium" })

#define COLOR_A ({ "red", "orange", "yellow", "green", "cyan", "blue", "violet", "pink", "mauve", "indigo", "brown", "cream", "gray", "black", "white", "purple" })

#define COLOR_B ({ "red", "orange", "yellow", "green", "blue", "violet", "brown", "black", "gray", "white", "cream" })

#define COLOR_C ({ "gold", "silver", "platinum", "mithril", "bronze", "brass", "steel", "iron", "electrum", "titanium", "arandur", "dlaran" })

#define COLOR_D ({ "red", "orange", "yellow", "green", "cyan", "blue", "violet", "pink", "mauve", "indigo", "brown", "cream", "gray", "black", "gold", "silver", "platinum", "brass", "bronze", "copper", "white", "purple" })

#define CLOTH_COLORS (["burlap" : COLOR_B, \
                       "wool" : COLOR_A, \
                       "silk" : COLOR_A, \
                       "homespun" : COLOR_B, \
                       "cotton" : COLOR_A, \
                       "linen" : COLOR_A, \
                       "velvet" : COLOR_D, \
                       "satin" : COLOR_D, \
                       "brocade" : COLOR_C, \
                       "suede" : COLOR_B, \
                       "lace" : COLOR_D, \
                       "chiffon" : COLOR_A, \
                       "crepe" : COLOR_A, \
                       "felt" : COLOR_B, \
                       "flannel" : COLOR_A, \
                       "broadcloth" : COLOR_A, \
                       "muslin" : \
                       ({ "natural", "white", "gray", }), \
                       "tweed" : COLOR_A, \
                       "gauze" : COLOR_A, \
                       "taffeta" : COLOR_A, \
                       "lame" : COLOR_C, \
                       "hemp" : COLOR_B, \
                      ])
