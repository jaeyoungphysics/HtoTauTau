ifeq ($(strip $(Demo/DemoAnalyzer)),)
ALL_COMMONRULES += src_Demo_DemoAnalyzer_src
src_Demo_DemoAnalyzer_src_parent := Demo/DemoAnalyzer
src_Demo_DemoAnalyzer_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Demo_DemoAnalyzer_src,src/Demo/DemoAnalyzer/src,LIBRARY))
DemoDemoAnalyzer := self/Demo/DemoAnalyzer
Demo/DemoAnalyzer := DemoDemoAnalyzer
DemoDemoAnalyzer_files := $(patsubst src/Demo/DemoAnalyzer/src/%,%,$(wildcard $(foreach dir,src/Demo/DemoAnalyzer/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
DemoDemoAnalyzer_BuildFile    := $(WORKINGDIR)/cache/bf/src/Demo/DemoAnalyzer/BuildFile
DemoDemoAnalyzer_LOC_USE := self  FWCore/Framework FWCore/PluginManager  DataFormats/MuonReco DataFormats/EgammaCandidates RecoMuon/TrackingTools FWCore/Utilities DataFormats/Math CommonTools/UtilAlgos DataFormats/VertexReco FWCore/ParameterSet CondFormats/JetMETObjects DataFormats/TrackReco DataFormats/PatCandidates RecoEgamma/EgammaTools EgammaAnalysis/ElectronTools HLTrigger/HLTcore
DemoDemoAnalyzer_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,DemoDemoAnalyzer,DemoDemoAnalyzer,$(SCRAMSTORENAME_LIB),src/Demo/DemoAnalyzer/src))
DemoDemoAnalyzer_PACKAGE := self/src/Demo/DemoAnalyzer/src
ALL_PRODS += DemoDemoAnalyzer
DemoDemoAnalyzer_CLASS := LIBRARY
Demo/DemoAnalyzer_forbigobj+=DemoDemoAnalyzer
DemoDemoAnalyzer_INIT_FUNC        += $$(eval $$(call Library,DemoDemoAnalyzer,src/Demo/DemoAnalyzer/src,src_Demo_DemoAnalyzer_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
