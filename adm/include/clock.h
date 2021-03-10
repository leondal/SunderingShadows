#define THE_BEGINNING 720561600
#define NOW(x) x-THE_BEGINNING

#define PI 3.141592653589793

#define SECOND 1
#define MINUTE 20
#define HOUR 1200
#define DAY 24000
#define WEEK 144000
#define MONTH 576000
#define YEAR 5760000

#define CURRENT_YEAR(x) (BASE_YEAR+((NOW(x))/(YEAR)))
#define CURRENT_MONTH(x) ((NOW(x))%YEAR)/MONTH
#define CURRENT_WEEK(x) ((NOW(x))%MONTH)/WEEK
#define CURRENT_DAY(x) ((NOW(x))%WEEK)/DAY
#define CURRENT_HOUR(x) ((NOW(x))%DAY)/HOUR
#define CURRENT_MINUTE(x) ((NOW(x))%HOUR)/MINUTE
#define CURRENT_SECOND(x) ((NOW(x))%20)

#define DAY_OF_THE_MONTH(x) ((NOW(x))%MONTH)/DAY
#define DAY_OF_THE_YEAR(x) ((NOW(x))%YEAR)/DAY

#define LONGEST_DAY 101
#define SHORTEST_DAY 1
#define BASE_YEAR 600

#define DAYS ({ "Shadowday", "Formday", "Waterday", "Flameday", "Lightday", "Lifeday" })
#define MONTHS ({ "Winterstime", "Renewal", "Springstime", "Plantingdays", "Sundays", "Summerstime", "Growingdays", "Harvestdays", "Autumnstime", "Colddays" })

