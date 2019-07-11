#!/usr/bin/env python

import os, sys, itertools

sys.path.append('/nfs/dust/cms/user/tholenhe/installs/varial-stable/Varial')


##################################### definition of UserConfig item changes ###

sys_uncerts = {
    # 'name' : {'item name': 'item value', ...},
     #'OPT01'                 : {'vvsqcd_min':'0.1'},
     #'OPT02'                 : {'vvsqcd_min':'0.2'},
     #'OPT03'                 : {'vvsqcd_min':'0.3'},
     #'OPT04'                 : {'vvsqcd_min':'0.4'},
     #'OPT05'                 : {'vvsqcd_min':'0.5'},
     #'OPT06'                 : {'vvsqcd_min':'0.6'},
     #'OPT07'                 : {'vvsqcd_min':'0.7'},
     #'OPT08'                 : {'vvsqcd_min':'0.8'},
     #'OPT09'                 : {'vvsqcd_min':'0.9'},
     #'OPT001'                 : {'vvsqcd_min':'0.01'},
     #'OPT003'                 : {'vvsqcd_min':'0.03'},
     #'OPT005'                 : {'vvsqcd_min':'0.05'},
     #'OPT007'                 : {'vvsqcd_min':'0.07'},
     #'OPT009'                 : {'vvsqcd_min':'0.09'},
     #'OPT011'                 : {'vvsqcd_min':'0.11'},
     #'OPT013'                 : {'vvsqcd_min':'0.13'},
     #'OPT015'                 : {'vvsqcd_min':'0.15'},
     #'OPT017'                 : {'vvsqcd_min':'0.17'},
     #'OPT019'                 : {'vvsqcd_min':'0.19'},
     'OPT071'                 : {'vvsqcd_min':'0.71'},
     'OPT073'                 : {'vvsqcd_min':'0.73'},
     'OPT075'                 : {'vvsqcd_min':'0.75'},
     'OPT077'                 : {'vvsqcd_min':'0.77'},
     'OPT079'                 : {'vvsqcd_min':'0.79'},
     'OPT081'                 : {'vvsqcd_min':'0.81'},
     'OPT083'                 : {'vvsqcd_min':'0.83'},
     'OPT085'                 : {'vvsqcd_min':'0.85'},
     'OPT087'                 : {'vvsqcd_min':'0.87'},
     'OPT089'                 : {'vvsqcd_min':'0.89'},
     'OPT091'                 : {'vvsqcd_min':'0.91'},
     'OPT093'                 : {'vvsqcd_min':'0.93'},
     'OPT095'                 : {'vvsqcd_min':'0.95'},
     'OPT097'                 : {'vvsqcd_min':'0.97'},
     'OPT099'                 : {'vvsqcd_min':'0.99'},
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
