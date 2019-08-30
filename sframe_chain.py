#!/usr/bin/env python

import os, sys, itertools

sys.path.append('/nfs/dust/cms/user/tholenhe/installs/varial-stable/Varial')


##################################### definition of UserConfig item changes ###

sys_uncerts = {
    # 'name' : {'item name': 'item value', ...},
     'DB010'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.1'},
     'DB020'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.2'},
     'DB030'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.3'},
     'DB040'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.4'},
     'DB050'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.5'},
     'DB060'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.6'},
     'DB070'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.7'},
     'DB080'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.8'},
     'DB090'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.9'},
     'DB071'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.71'},
     'DB073'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.73'},
     'DB075'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.75'},
     'DB077'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.77'},
     'DB079'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.79'},
     'DB081'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.81'},
     'DB083'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.83'},
     'DB085'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.85'},
     'DB087'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.87'},
     'DB089'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.89'},
     'DB091'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.91'},
     'DB093'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.93'},
     'DB095'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.95'},
     'DB097'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.97'},
     'DB099'                 : {'use_deep_boosted':'true','vvsqcd_min':'0.99'},
     'TAU015'                 : {'use_deep_boosted':'false','tau21_sel':'0.15'},
     'TAU020'                 : {'use_deep_boosted':'false','tau21_sel':'0.20'},
     'TAU025'                 : {'use_deep_boosted':'false','tau21_sel':'0.25'},
     'TAU030'                 : {'use_deep_boosted':'false','tau21_sel':'0.30'},
     'TAU035'                 : {'use_deep_boosted':'false','tau21_sel':'0.35'},
     'TAU040'                 : {'use_deep_boosted':'false','tau21_sel':'0.40'},
     'TAU045'                 : {'use_deep_boosted':'false','tau21_sel':'0.45'},
     'TAU050'                 : {'use_deep_boosted':'false','tau21_sel':'0.50'},
     'TAU055'                 : {'use_deep_boosted':'false','tau21_sel':'0.55'},
     'TAU060'                 : {'use_deep_boosted':'false','tau21_sel':'0.60'},
     'TAU065'                 : {'use_deep_boosted':'false','tau21_sel':'0.65'},
     'TAU070'                 : {'use_deep_boosted':'false','tau21_sel':'0.70'},
     'TAU075'                 : {'use_deep_boosted':'false','tau21_sel':'0.75'},
     'TAU080'                 : {'use_deep_boosted':'false','tau21_sel':'0.80'},
     'TAU085'                 : {'use_deep_boosted':'false','tau21_sel':'0.85'},
     'TAU090'                 : {'use_deep_boosted':'false','tau21_sel':'0.90'},
     'TAU095'                 : {'use_deep_boosted':'false','tau21_sel':'0.95'},
}
start_all_parallel = True

############################################################### script code ###
import varial
import sys
import os

if len(sys.argv) != 2:
    print 'Plz. give me da name of da sframe-config! ... dude!'
    exit(-1)


def set_uncert_func(uncert_name):
    uncert = sys_uncerts[uncert_name]
    def do_set_uncert(element_tree):
        cycle = element_tree.getroot().find('Cycle')
        user_config = cycle.find('UserConfig')
        output_dir = cycle.get('OutputDirectory')

        cycle.set('OutputDirectory', os.path.join(output_dir, uncert_name+'/'))

        for name, value in uncert.iteritems():
            uc_item = list(i for i in user_config if i.get('Name') == name)
            assert uc_item, 'could not find item with name: %s' % name
            uc_item[0].set('Value', value)

    return do_set_uncert


from varial.extensions.sframe import SFrame
from varial import tools
if start_all_parallel:
    ToolChain = tools.ToolChainParallel
else:
    ToolChain = tools.ToolChain


class MySFrameBatch(SFrame):

    def configure(self):
        self.xml_doctype = self.xml_doctype + """
<!--
   <ConfigParse NEventsBreak="100000" FileSplit="0" AutoResubmit="0" />
   <ConfigSGE RAM ="2" DISK ="2" Mail="heiner@cern.de" Notification="as" Workdir="workdir"/>
-->
"""
        if os.path.exists(self.cwd + 'workdir'):
            opt = ' -rl --exitOnQuestion'
        else:
            opt = ' -sl --exitOnQuestion'

        self.exe = 'sframe_batch.py' + opt


sframe_tools = ToolChain(
    'SFrameChain',
    list(
        SFrame(
            cfg_filename=sys.argv[1],
            xml_tree_callback=set_uncert_func(uncert),
            name='SFrame_' + uncert,
            halt_on_exception=False,
        ) 
        for uncert in sys_uncerts
    )
)


if __name__ == '__main__':
    varial.tools.Runner(sframe_tools)



     #'NOMINAL'               : {'Do_Permutations':'false', 'Permutation':'-1'},    
     #'OPT01'                 : {'Do_Permutations':'true' , 'Permutation':'1'},
     #'OPT02'                 : {'Do_Permutations':'true' , 'Permutation':'2'},
     #'OPT03'                 : {'Do_Permutations':'true' , 'Permutation':'3'},
     #'OPT04'                 : {'Do_Permutations':'true' , 'Permutation':'4'},
     #'OPT05'                 : {'Do_Permutations':'true' , 'Permutation':'5'},
     #'OPT06'                 : {'Do_Permutations':'true' , 'Permutation':'6'},
     #'OPT07'                 : {'Do_Permutations':'true' , 'Permutation':'7'},
     #'OPT08'                 : {'Do_Permutations':'true' , 'Permutation':'8'},
     #'OPT09'                 : {'Do_Permutations':'true' , 'Permutation':'9'},
     #'OPT10'                 : {'Do_Permutations':'true' , 'Permutation':'10'},
     #'OPT11'                 : {'Do_Permutations':'true' , 'Permutation':'11'},
     #'OPT12'                 : {'Do_Permutations':'true' , 'Permutation':'12'},
     #'OPT13'                 : {'Do_Permutations':'true' , 'Permutation':'13'},
     #'OPT14'                 : {'Do_Permutations':'true' , 'Permutation':'14'},
     #'OPT15'                 : {'Do_Permutations':'true' , 'Permutation':'15'},
     #'OPT16'                 : {'Do_Permutations':'true' , 'Permutation':'16'},
     #'OPT17'                 : {'Do_Permutations':'true' , 'Permutation':'17'},
     #'OPT18'                 : {'Do_Permutations':'true' , 'Permutation':'18'},
     #'OPT19'                 : {'Do_Permutations':'true' , 'Permutation':'19'},
     #'OPT20'                 : {'Do_Permutations':'true' , 'Permutation':'20'},
     #'OPT21'                 : {'Do_Permutations':'true' , 'Permutation':'21'},
     #'OPT22'                 : {'Do_Permutations':'true' , 'Permutation':'22'},
     #'OPT23'                 : {'Do_Permutations':'true' , 'Permutation':'23'},
     #'OPT24'                 : {'Do_Permutations':'true' , 'Permutation':'24'},
     #'OPT25'                 : {'Do_Permutations':'true' , 'Permutation':'25'},
     #'OPT26'                 : {'Do_Permutations':'true' , 'Permutation':'26'},
     #'OPT27'                 : {'Do_Permutations':'true' , 'Permutation':'27'},

     #'NOMINAL'               : {'Do_Permutations':'false', 'Permutation':'-1'},
     #'NewOPT01'              : {'Do_Permutations':'true' , 'Permutation':'1'},
     #'NewOPT02'              : {'Do_Permutations':'true' , 'Permutation':'2'},
     #'NewOPT03'              : {'Do_Permutations':'true' , 'Permutation':'3'},
     #'NewOPT04'              : {'Do_Permutations':'true' , 'Permutation':'4'},
     #'NewOPT05'              : {'Do_Permutations':'true' , 'Permutation':'5'},
     #'NewOPT06'              : {'Do_Permutations':'true' , 'Permutation':'6'},
     #'NewOPT07'              : {'Do_Permutations':'true' , 'Permutation':'7'},
     #'NewOPT08'              : {'Do_Permutations':'true' , 'Permutation':'8'},
     #'NewOPT09'              : {'Do_Permutations':'true' , 'Permutation':'9'},
     #'NewOPT10'              : {'Do_Permutations':'true' , 'Permutation':'10'},
