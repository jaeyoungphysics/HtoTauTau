import FWCore.ParameterSet.Config as cms

import FWCore.Utilities.FileUtils as FileUtils

#from Demo.DemoAnalyzer.demoanalzyer_cfi import *


process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(50000) )

#files = FileUtils.loadListFromFile("/home/cmsusr/CMSSW_5_3_32/src/CMS_Run2012B_TauPlusX_AOD_22Jan2013-v1_20000_file_index.txt")
#files = FileUtils.loadListFromFile("/home/jykim/CMSSW_5_3_32/src/CMS_MonteCarlo2012_Summer12_DR53X_VBF_HToTauTau_M-125_8TeV-powheg-pythia6-tauola-tauPolarOff_AODSIM_PU_S10_START53_V19-v1_00000_file_index.txt")
files = FileUtils.loadListFromFile("/home/jykim/jykim/ggH_list.txt")


#files.extend(FileUtils.loadListFromFile("/home/cmsusr/CMSSW_5_3_32/src/CMS_Run2012B_TauPlusX_AOD_22Jan2013-v1_20000_file_index.txt"))
#files.extend(FileUtils.loadListFromFile("/home/jykim/CMSSW_5_3_32/src/CMS_MonteCarlo2012_Summer12_DR53X_VBF_HToTauTau_M-125_8TeV-powheg-pythia6-tauola-tauPolarOff_AODSIM_PU_S10_START53_V19-v1_00000_file_index.txt"))
#files.extend(FileUtils.loadListFromFile("/home/jykim/jykim/gg_list.txt"))

process.source = cms.Source(
   "PoolSource", fileNames=cms.untracked.vstring(*files))

"""
process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'root://eospublic.cern.ch//eos/opendata/cms/Run2012B/TauPlusX/AOD/22Jan2013-v1/20000/0040CF04-8E74-E211-AD0C-00266CFFA344.root'
    )
)
"""

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
#globaltag for 2012 collision data
#process.GlobalTag.connect = cms.string('sqlite_file:/cvmfs/cms-opendata-conddb.cern.ch/FT53_V21A_AN6_FULL.db')
process.GlobalTag.globaltag = 'FT53_V21A_AN6::All'



process.demo = cms.EDAnalyzer('DemoAnalyzer',
	InputCollection = cms.InputTag("muons")
)

process.mytaus = cms.EDAnalyzer('TauAnalyzer',
                                InputCollection = cms.InputTag("hpsPFTauProducer")
                                )



#---- Configure the output ROOT filename
process.TFileService = cms.Service(
        "TFileService", fileName=cms.string("myoutput.root"))


process.p = cms.Path(process.demo+process.mytaus)
