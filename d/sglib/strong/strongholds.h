#include <std.h>
#include <objects.h>

#define STRONGDIR       "/d/sglib/strong/"
#define RDAEMONDIR      "/d/sglib/strong/save/"
#define RMARKERDIR      "/d/sglib/strong/save/markers/"
#define RDATADIR        "/d/sglib/strong/save/data/"

#define MARKER          STRONGDIR+"strongmarker"
#define SROOM           STRONGDIR+"strongroom"
#define SDAEMON         STRONGDIR+"strong_d"
#define SSTRONGDIR      STRONGDIR+"strongholds.db"
#define MARKERID        "markerx"

#define IDFORMULA       this_object()->query_owner()+time()+random(10)

#define STRONG_COST     10
#define HIDDEN_COST     50
#define COST_MOD        1000
#define PROTECT_COST    ({ 2,4,8,16,32,64,128,256,512,1024,2046,4096,8192,16384,32768 })
