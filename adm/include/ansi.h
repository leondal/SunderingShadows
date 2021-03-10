/* ansi.h  ... include file for ansi color codes .... Melvaig 28/3/92 */

//#define ESC ""
#define ESC "\x1B"

                          /* escape code (^[) can not be added with mud
                           * editor due to filtering . Patch this from
                           * the mud account or ftp this file in bin mode */

#define XCH ESC+"[7m"       /* reverse (exchange) */
#define RED ESC+"[31m"
#define GRN ESC+"[32m"
#define YEL ESC+"[33m"
#define BLU ESC+"[34m"
#define MAG ESC+"[35m"      /* magenta is a sort of purple */
#define CYN ESC+"[36m"      /* cyan is a light blue */
#define WHT ESC+"[37m"


#define HIN ESC+"[1m"       /* These are high intensity color codes     */
#define HIX ESC+"[1;7m"
#define HIR ESC+"[1;31m"
#define HIG ESC+"[1;32m"
#define HIY ESC+"[1;33m"
#define HIB ESC+"[1;34m"
#define HIM ESC+"[1;35m"
#define HIC ESC+"[1;36m"
#define HIW ESC+"[1;37m"   /* High intensity white */

                             /* Background colors - added 3-3-93 Melvaig */

#define RBA ESC+"[41m"       /* Red BAckground                       */
#define GBA ESC+"[42m"       /* Green BAckground                     */
#define YBA ESC+"[43m"       /* Yellow BAckground   (looks brown)        */
#define BBA ESC+"[44m"       /* Blue BAckground                      */
#define MBA ESC+"[45m"       /* Magenta is a sort of purple          */
#define CBA ESC+"[46m"       /* Cyan is a light blue                 */
#define WBA ESC+"[47m"       /* dull White BAckground (greyish) */


#define NOR ESC+"[37;40;0m"   /* Set screen to normal (hopefully)  */

