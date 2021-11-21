import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer('DemoAnalyzer',
        InputCollection = cms.InputTag("muons")	
)

mytaus = cms.EDAnalyzer('TauAnalyzer',
	InputCollection = cms.InputTag("hpsPFTauProducer")
)


