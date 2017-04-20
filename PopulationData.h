#pragma once

#include <cstdint>
#include <string>
#include <array>
#include "StateId.h"

/*
Source: https://www.census.gov/data/tables/2016/demo/popest/state-total.html

Geography
Census                  2010          2011          2012          2013          2014          2015          2016
----------------------------------------------------------------------------------------------------------------------
Alabama                  4'779'736     4'799'918     4'815'960     4'829'479     4'843'214     4'853'875     4'863'300
Alaska                     710'231       722'713       731'089       736'879       736'705       737'709       741'894
Arizona                  6'392'017     6'467'163     6'549'634     6'624'617     6'719'993     6'817'565     6'931'071
Arkansas                 2'915'918     2'939'493     2'950'685     2'958'663     2'966'912     2'977'853     2'988'248
California              37'253'956    37'676'861    38'011'074    38'335'203    38'680'810    38'993'940    39'250'017
Colorado                 5'029'196     5'118'360     5'189'867     5'267'603     5'349'648     5'448'819     5'540'545
Connecticut              3'574'097     3'589'893     3'593'795     3'596'003     3'591'873     3'584'730     3'576'452
Delaware                   897'934       907'924       916'993       925'395       934'948       944'076       952'065
District of Columbia       601'723       620'477       635'327       649'165       659'005       670'377       681'170
Florida                 18'801'310    19'096'952    19'344'156    19'582'022    19'888'741    20'244'914    20'612'439
Georgia                  9'687'653     9'811'610     9'914'668     9'984'938    10'087'231    10'199'398    10'310'371
Hawaii                   1'360'301     1'377'864     1'391'820     1'406'481     1'416'349     1'425'157     1'428'557
Idaho                    1'567'582     1'584'143     1'595'911     1'612'011     1'633'532     1'652'828     1'683'140
Illinois                12'830'632    12'860'012    12'870'798    12'879'505    12'867'544    12'839'047    12'801'539
Indiana                  6'483'802     6'516'480     6'537'743     6'569'102     6'595'233     6'612'768     6'633'053
Iowa                     3'046'355     3'065'223     3'076'310     3'091'930     3'108'030     3'121'997     3'134'693
Kansas                   2'853'118     2'869'503     2'885'262     2'892'821     2'899'360     2'906'721     2'907'289
Kentucky                 4'339'367     4'369'354     4'384'799     4'400'477     4'413'057     4'424'611     4'436'974
Louisiana                4'533'372     4'575'404     4'603'429     4'626'402     4'647'880     4'668'960     4'681'666
Maine                    1'328'361     1'328'231     1'328'895     1'329'076     1'330'719     1'329'453     1'331'479
Maryland                 5'773'552     5'843'603     5'889'651     5'931'129     5'967'295     5'994'983     6'016'447
Massachusetts            6'547'629     6'611'923     6'658'008     6'706'786     6'749'911     6'784'240     6'811'779
Michigan                 9'883'640     9'876'213     9'887'238     9'898'982     9'915'767     9'917'715     9'928'300
Minnesota                5'303'925     5'348'562     5'380'285     5'418'521     5'453'109     5'482'435     5'519'952
Mississippi              2'967'297     2'978'162     2'984'945     2'990'482     2'992'400     2'989'390     2'988'726
Missouri                 5'988'927     6'010'717     6'025'415     6'042'711     6'060'930     6'076'204     6'093'000
Montana                    989'415       997'821     1'005'196     1'014'314     1'022'867     1'032'073     1'042'520
Nebraska                 1'826'341     1'842'283     1'855'725     1'868'559     1'881'145     1'893'765     1'907'116
Nevada                   2'700'551     2'718'379     2'752'565     2'786'464     2'833'013     2'883'758     2'940'058
New Hampshire            1'316'470     1'318'473     1'321'182     1'322'687     1'328'743     1'330'111     1'334'795
New Jersey               8'791'894     8'841'243     8'873'211     8'899'162     8'925'001     8'935'421     8'944'469
New Mexico               2'059'179     2'077'756     2'083'784     2'085'193     2'083'024     2'080'328     2'081'015
New York                19'378'102    19'519'529    19'602'769    19'673'546    19'718'515    19'747'183    19'745'289
North Carolina           9'535'483     9'650'963     9'746'175     9'841'590     9'934'399    10'035'186    10'146'788
North Dakota               672'591       685'476       702'087       724'019       739'904       756'835       757'952
Ohio                    11'536'504    11'544'824    11'550'839    11'570'022    11'594'408    11'605'090    11'614'373
Oklahoma                 3'751'351     3'786'274     3'817'054     3'852'415     3'877'499     3'907'414     3'923'561
Oregon                   3'831'074     3'868'031     3'899'116     3'925'751     3'968'371     4'024'634     4'093'465
Pennsylvania            12'702'379    12'744'293    12'771'854    12'781'338    12'790'565    12'791'904    12'784'227
Rhode Island             1'052'567     1'052'451     1'052'901     1'053'033     1'054'480     1'055'607     1'056'426
South Carolina           4'625'364     4'672'637     4'720'760     4'767'894     4'828'430     4'894'834     4'961'119
South Dakota               814'180       824'398       834'441       844'922       852'561       857'919       865'454
Tennessee                6'346'105     6'397'634     6'454'306     6'494'821     6'544'663     6'595'056     6'651'194
Texas                   25'145'561    25'646'389    26'071'655    26'473'525    26'944'751    27'429'639    27'862'596
Utah                     2'763'885     2'816'124     2'855'782     2'902'663     2'941'836     2'990'632     3'051'217
Vermont                    625'741       626'730       626'444       627'140       626'984       626'088       624'594
Virginia                 8'001'024     8'110'035     8'192'048     8'262'692     8'317'372     8'367'587     8'411'808
Washington               6'724'540     6'822'520     6'895'226     6'968'006     7'054'196     7'160'290     7'288'000
West Virginia            1'852'994     1'854'972     1'856'560     1'853'231     1'848'514     1'841'053     1'831'102
Wisconsin                5'686'986     5'709'640     5'726'177     5'742'854     5'758'377     5'767'891     5'778'708
Wyoming                    563'626       567'725       576'765       582'684       583'642       586'555       585'501

*/

using PopulationEstimateYear = std::size_t;

constexpr PopulationEstimateYear c_lastCensusYear{ 2010 };
constexpr PopulationEstimateYear c_nextCensusYear{ 2020 };
constexpr PopulationEstimateYear c_endEstimateYear{ 2016 };

constexpr auto GetPopulationArrayIndexFromYear(PopulationEstimateYear year)
{
    if (year >= c_lastCensusYear && year <= c_nextCensusYear)
    {
        return year - c_lastCensusYear;
    }
    else
    {
        throw std::invalid_argument("Invalid year for census prediction");
    }
}

using PopulationAmount = std::uint32_t;
using PopulationArray = std::array<PopulationAmount, c_nextCensusYear - c_lastCensusYear + 1>;

constexpr PopulationAmount c_NoProjection{ UINT32_MAX };

constexpr auto BuildPopulationArray(StateId state) noexcept
{
    switch (state)
    {
    case StateId::ALABAMA:
        return PopulationArray{ 4'779'736, 4'799'918, 4'815'960, 4'829'479, 4'843'214, 4'853'875, 4'863'300, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::ALASKA:
        return PopulationArray{ 710'231, 722'713, 731'089, 736'879, 736'705, 737'709, 741'894, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::ARIZONA:
        return PopulationArray{ 6'392'017, 6'467'163, 6'549'634, 6'624'617, 6'719'993, 6'817'565, 6'931'071, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::ARKANSAS:
        return PopulationArray{ 2'915'918, 2'939'493, 2'950'685, 2'958'663, 2'966'912, 2'977'853, 2'988'248, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::CALIFORNIA:
        return PopulationArray{ 37'253'956, 37'676'861, 38'011'074, 38'335'203, 38'680'810, 38'993'940, 39'250'017, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::COLORADO:
        return PopulationArray{ 5'029'196, 5'118'360, 5'189'867, 5'267'603, 5'349'648, 5'448'819, 5'540'545, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::CONNECTICUT:
        return PopulationArray{ 3'574'097, 3'589'893, 3'593'795, 3'596'003, 3'591'873, 3'584'730, 3'576'452, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::DELAWARE:
        return PopulationArray{ 897'934, 907'924, 916'993, 925'395, 934'948, 944'076, 952'065, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::FLORIDA:
        return PopulationArray{ 18'801'310, 19'096'952, 19'344'156, 19'582'022, 19'888'741, 20'244'914, 20'612'439, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::GEORGIA:
        return PopulationArray{ 9'687'653, 9'811'610, 9'914'668, 9'984'938, 10'087'231, 10'199'398, 10'310'371, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::HAWAII:
        return PopulationArray{ 1'360'301, 1'377'864, 1'391'820, 1'406'481, 1'416'349, 1'425'157, 1'428'557, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::IDAHO:
        return PopulationArray{ 1'567'582, 1'584'143, 1'595'911, 1'612'011, 1'633'532, 1'652'828, 1'683'140, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::ILLINOIS:
        return PopulationArray{ 12'830'632, 12'860'012, 12'870'798, 12'879'505, 12'867'544, 12'839'047, 12'801'539, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::INDIANA:
        return PopulationArray{ 6'483'802, 6'516'480, 6'537'743, 6'569'102, 6'595'233, 6'612'768, 6'633'053, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::IOWA:
        return PopulationArray{ 3'046'355, 3'065'223, 3'076'310, 3'091'930, 3'108'030, 3'121'997, 3'134'693, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::KANSAS:
        return PopulationArray{ 2'853'118, 2'869'503, 2'885'262, 2'892'821, 2'899'360, 2'906'721, 2'907'289, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::KENTUCKY:
        return PopulationArray{ 4'339'367, 4'369'354, 4'384'799, 4'400'477, 4'413'057, 4'424'611, 4'436'974, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::LOUISIANA:
        return PopulationArray{ 4'533'372, 4'575'404, 4'603'429, 4'626'402, 4'647'880, 4'668'960, 4'681'666, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::MAINE:
        return PopulationArray{ 1'328'361, 1'328'231, 1'328'895, 1'329'076, 1'330'719, 1'329'453, 1'331'479, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::MARYLAND:
        return PopulationArray{ 5'773'552, 5'843'603, 5'889'651, 5'931'129, 5'967'295, 5'994'983, 6'016'447, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::MASSACHUSETTS:
        return PopulationArray{ 6'547'629, 6'611'923, 6'658'008, 6'706'786, 6'749'911, 6'784'240, 6'811'779, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::MICHIGAN:
        return PopulationArray{ 9'883'640, 9'876'213, 9'887'238, 9'898'982, 9'915'767, 9'917'715, 9'928'300, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::MINNESOTA:
        return PopulationArray{ 5'303'925, 5'348'562, 5'380'285, 5'418'521, 5'453'109, 5'482'435, 5'519'952, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::MISSISSIPPI:
        return PopulationArray{ 2'967'297, 2'978'162, 2'984'945, 2'990'482, 2'992'400, 2'989'390, 2'988'726, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::MISSOURI:
        return PopulationArray{ 5'988'927, 6'010'717, 6'025'415, 6'042'711, 6'060'930, 6'076'204, 6'093'000, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::MONTANA:
        return PopulationArray{ 989'415, 997'821, 1'005'196, 1'014'314, 1'022'867, 1'032'073, 1'042'520, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::NEBRASKA:
        return PopulationArray{ 1'826'341, 1'842'283, 1'855'725, 1'868'559, 1'881'145, 1'893'765, 1'907'116, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::NEVADA:
        return PopulationArray{ 2'700'551, 2'718'379, 2'752'565, 2'786'464, 2'833'013, 2'883'758, 2'940'058, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::NEW_HAMPSHIRE:
        return PopulationArray{ 1'316'470, 1'318'473, 1'321'182, 1'322'687, 1'328'743, 1'330'111, 1'334'795, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::NEW_JERSEY:
        return PopulationArray{ 8'791'894, 8'841'243, 8'873'211, 8'899'162, 8'925'001, 8'935'421, 8'944'469, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::NEW_MEXICO:
        return PopulationArray{ 2'059'179, 2'077'756, 2'083'784, 2'085'193, 2'083'024, 2'080'328, 2'081'015, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::NEW_YORK:
        return PopulationArray{ 19'378'102, 19'519'529, 19'602'769, 19'673'546, 19'718'515, 19'747'183, 19'745'289, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::NORTH_CAROLINA:
        return PopulationArray{ 9'535'483, 9'650'963, 9'746'175, 9'841'590, 9'934'399, 10'035'186, 10'146'788, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::NORTH_DAKOTA:
        return PopulationArray{ 672'591, 685'476, 702'087, 724'019, 739'904, 756'835, 757'952, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::OHIO:
        return PopulationArray{ 11'536'504, 11'544'824, 11'550'839, 11'570'022, 11'594'408, 11'605'090, 11'614'373, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::OKLAHOMA:
        return PopulationArray{ 3'751'351, 3'786'274, 3'817'054, 3'852'415, 3'877'499, 3'907'414, 3'923'561, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::OREGON:
        return PopulationArray{ 3'831'074, 3'868'031, 3'899'116, 3'925'751, 3'968'371, 4'024'634, 4'093'465, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::PENNSYLVANIA:
        return PopulationArray{ 12'702'379, 12'744'293, 12'771'854, 12'781'338, 12'790'565, 12'791'904, 12'784'227, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::RHODE_ISLAND:
        return PopulationArray{ 1'052'567, 1'052'451, 1'052'901, 1'053'033, 1'054'480, 1'055'607, 1'056'426, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::SOUTH_CAROLINA:
        return PopulationArray{ 4'625'364, 4'672'637, 4'720'760, 4'767'894, 4'828'430, 4'894'834, 4'961'119, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::SOUTH_DAKOTA:
        return PopulationArray{ 814'180, 824'398, 834'441, 844'922, 852'561, 857'919, 865'454, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::TENNESSEE:
        return PopulationArray{ 6'346'105, 6'397'634, 6'454'306, 6'494'821, 6'544'663, 6'595'056, 6'651'194, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::TEXAS:
        return PopulationArray{ 25'145'561, 25'646'389, 26'071'655, 26'473'525, 26'944'751, 27'429'639, 27'862'596, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::UTAH:
        return PopulationArray{ 2'763'885, 2'816'124, 2'855'782, 2'902'663, 2'941'836, 2'990'632, 3'051'217, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::VERMONT:
        return PopulationArray{ 625'741, 626'730, 626'444, 627'140, 626'984, 626'088, 624'594, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::VIRGINIA:
        return PopulationArray{ 8'001'024, 8'110'035, 8'192'048, 8'262'692, 8'317'372, 8'367'587, 8'411'808, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::WASHINGTON:
        return PopulationArray{ 6'724'540, 6'822'520, 6'895'226, 6'968'006, 7'054'196, 7'160'290, 7'288'000, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::WEST_VIRGINIA:
        return PopulationArray{ 1'852'994, 1'854'972, 1'856'560, 1'853'231, 1'848'514, 1'841'053, 1'831'102, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::WISCONSIN:
        return PopulationArray{ 5'686'986, 5'709'640, 5'726'177, 5'742'854, 5'758'377, 5'767'891, 5'778'708, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    case StateId::WYOMING:
        return PopulationArray{ 563'626, 567'725, 576'765, 582'684, 583'642, 586'555, 585'501, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    default:
        return PopulationArray{ c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection, c_NoProjection };
    }
}

struct PopulationEstimate
{
    PopulationArray m_data;

    constexpr explicit PopulationEstimate(StateId state) noexcept
        : m_data( BuildPopulationArray(state) )
    {
    }
};

using StatePopulationEstimates = std::array<PopulationEstimate, MaxStateId>;

constexpr StatePopulationEstimates c_statePopulationEstimates
{
    PopulationEstimate{ StateId::ALABAMA },
    PopulationEstimate{ StateId::ALASKA },
    PopulationEstimate{ StateId::ARIZONA },
    PopulationEstimate{ StateId::ARKANSAS },
    PopulationEstimate{ StateId::CALIFORNIA },
    PopulationEstimate{ StateId::COLORADO },
    PopulationEstimate{ StateId::CONNECTICUT },
    PopulationEstimate{ StateId::DELAWARE },
    PopulationEstimate{ StateId::FLORIDA },
    PopulationEstimate{ StateId::GEORGIA },
    PopulationEstimate{ StateId::HAWAII },
    PopulationEstimate{ StateId::IDAHO },
    PopulationEstimate{ StateId::ILLINOIS },
    PopulationEstimate{ StateId::INDIANA },
    PopulationEstimate{ StateId::IOWA },
    PopulationEstimate{ StateId::KANSAS },
    PopulationEstimate{ StateId::KENTUCKY },
    PopulationEstimate{ StateId::LOUISIANA },
    PopulationEstimate{ StateId::MAINE },
    PopulationEstimate{ StateId::MARYLAND },
    PopulationEstimate{ StateId::MASSACHUSETTS },
    PopulationEstimate{ StateId::MICHIGAN },
    PopulationEstimate{ StateId::MINNESOTA },
    PopulationEstimate{ StateId::MISSISSIPPI },
    PopulationEstimate{ StateId::MISSOURI },
    PopulationEstimate{ StateId::MONTANA },
    PopulationEstimate{ StateId::NEBRASKA },
    PopulationEstimate{ StateId::NEVADA },
    PopulationEstimate{ StateId::NEW_HAMPSHIRE },
    PopulationEstimate{ StateId::NEW_JERSEY },
    PopulationEstimate{ StateId::NEW_MEXICO },
    PopulationEstimate{ StateId::NEW_YORK },
    PopulationEstimate{ StateId::NORTH_CAROLINA },
    PopulationEstimate{ StateId::NORTH_DAKOTA },
    PopulationEstimate{ StateId::OHIO },
    PopulationEstimate{ StateId::OKLAHOMA },
    PopulationEstimate{ StateId::OREGON },
    PopulationEstimate{ StateId::PENNSYLVANIA },
    PopulationEstimate{ StateId::RHODE_ISLAND },
    PopulationEstimate{ StateId::SOUTH_CAROLINA },
    PopulationEstimate{ StateId::SOUTH_DAKOTA },
    PopulationEstimate{ StateId::TENNESSEE },
    PopulationEstimate{ StateId::TEXAS },
    PopulationEstimate{ StateId::UTAH },
    PopulationEstimate{ StateId::VERMONT },
    PopulationEstimate{ StateId::VIRGINIA },
    PopulationEstimate{ StateId::WASHINGTON },
    PopulationEstimate{ StateId::WEST_VIRGINIA },
    PopulationEstimate{ StateId::WISCONSIN },
    PopulationEstimate{ StateId::WYOMING }
};
