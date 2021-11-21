ifeq ($(strip $(PyDemoDemoAnalyzer)),)
PyDemoDemoAnalyzer := self/src/Demo/DemoAnalyzer/python
src_Demo_DemoAnalyzer_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Demo/DemoAnalyzer/python)
PyDemoDemoAnalyzer_files := $(patsubst src/Demo/DemoAnalyzer/python/%,%,$(wildcard $(foreach dir,src/Demo/DemoAnalyzer/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyDemoDemoAnalyzer_LOC_USE := self  
PyDemoDemoAnalyzer_PACKAGE := self/src/Demo/DemoAnalyzer/python
ALL_PRODS += PyDemoDemoAnalyzer
PyDemoDemoAnalyzer_INIT_FUNC        += $$(eval $$(call PythonProduct,PyDemoDemoAnalyzer,src/Demo/DemoAnalyzer/python,src_Demo_DemoAnalyzer_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyDemoDemoAnalyzer,src/Demo/DemoAnalyzer/python))
endif
ALL_COMMONRULES += src_Demo_DemoAnalyzer_python
src_Demo_DemoAnalyzer_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Demo_DemoAnalyzer_python,src/Demo/DemoAnalyzer/python,PYTHON))
