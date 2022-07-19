<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="20008000">
	<Item Name="我的电脑" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="cccc" Type="Folder">
			<Item Name="test_fmcw.vi" Type="VI" URL="../example/test_fmcw.vi"/>
		</Item>
		<Item Name="example" Type="Folder">
			<Item Name="ai_continuous_and_ao_waveform_pc_infinite.vi" Type="VI" URL="../example/ai_continuous_and_ao_waveform_pc_infinite.vi"/>
			<Item Name="ai_continuous_full.vi" Type="VI" URL="../example/ai_continuous_full.vi"/>
			<Item Name="ai_continuous_lite.vi" Type="VI" URL="../example/ai_continuous_lite.vi"/>
			<Item Name="ai_oneshot_ext_trig_in.vi" Type="VI" URL="../example/ai_oneshot_ext_trig_in.vi"/>
			<Item Name="ai_oneshot_full.vi" Type="VI" URL="../example/ai_oneshot_full.vi"/>
			<Item Name="ai_oneshot_lite.vi" Type="VI" URL="../example/ai_oneshot_lite.vi"/>
			<Item Name="ao_dc_voltage.vi" Type="VI" URL="../example/ao_dc_voltage.vi"/>
			<Item Name="ao_dc_voltage_pc_timed.vi" Type="VI" URL="../example/ao_dc_voltage_pc_timed.vi"/>
			<Item Name="ao_waveform_full.vi" Type="VI" URL="../example/ao_waveform_full.vi"/>
			<Item Name="ao_waveform_lite.vi" Type="VI" URL="../example/ao_waveform_lite.vi"/>
			<Item Name="ao_waveform_pc_infinite.vi" Type="VI" URL="../example/ao_waveform_pc_infinite.vi"/>
			<Item Name="ao_waveform_sync.vi" Type="VI" URL="../example/ao_waveform_sync.vi"/>
			<Item Name="di_continuous_full.vi" Type="VI" URL="../example/di_continuous_full.vi"/>
			<Item Name="di_continuous_lite.vi" Type="VI" URL="../example/di_continuous_lite.vi"/>
			<Item Name="di_oneshot_full.vi" Type="VI" URL="../example/di_oneshot_full.vi"/>
			<Item Name="di_oneshot_lite.vi" Type="VI" URL="../example/di_oneshot_lite.vi"/>
			<Item Name="do_immediately.vi" Type="VI" URL="../example/do_immediately.vi"/>
			<Item Name="do_waveform_full.vi" Type="VI" URL="../example/do_waveform_full.vi"/>
			<Item Name="do_waveform_lite.vi" Type="VI" URL="../example/do_waveform_lite.vi"/>
			<Item Name="do_waveform_pc_infinite.vi" Type="VI" URL="../example/do_waveform_pc_infinite.vi"/>
		</Item>
		<Item Name="lib" Type="Folder">
			<Item Name="x64" Type="Folder">
				<Item Name="USB5000.dll" Type="Document" URL="../../lib/x64/USB5000.dll"/>
				<Item Name="USB5000.lib" Type="Document" URL="../../lib/x64/USB5000.lib"/>
			</Item>
			<Item Name="USB5000.h" Type="Document" URL="../../lib/USB5000.h"/>
		</Item>
		<Item Name="sub vi USB 5000" Type="Folder">
			<Item Name="FindUSB5DAQ.vi" Type="VI" URL="../sub vi USB 5000/FindUSB5DAQ.vi"/>
			<Item Name="SetUSB5AiChanSel.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AiChanSel.vi"/>
			<Item Name="SetUSB5AiConvSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AiConvSource.vi"/>
			<Item Name="SetUSB5AiOneShotPoints.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AiOneShotPoints.vi"/>
			<Item Name="SetUSB5AiPreTrigPoints.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AiPreTrigPoints.vi"/>
			<Item Name="SetUSB5AiRange.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AiRange.vi"/>
			<Item Name="SetUSB5AiSampleMode.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AiSampleMode.vi"/>
			<Item Name="SetUSB5AiSampleRate.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AiSampleRate.vi"/>
			<Item Name="SetUSB5AiSoftTrig.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AiSoftTrig.vi"/>
			<Item Name="SetUSB5AiTrigSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AiTrigSource.vi"/>
			<Item Name="SetUSB5AoConvSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AoConvSource.vi"/>
			<Item Name="SetUSB5AoCycle.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AoCycle.vi"/>
			<Item Name="SetUSB5AoDataFifo.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AoDataFifo.vi"/>
			<Item Name="SetUSB5AoImmediately.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AoImmediately.vi"/>
			<Item Name="SetUSB5AoSampleMode.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AoSampleMode.vi"/>
			<Item Name="SetUSB5AoSampleRate.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AoSampleRate.vi"/>
			<Item Name="SetUSB5AoSoftTrig.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AoSoftTrig.vi"/>
			<Item Name="SetUSB5AoSync.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AoSync.vi"/>
			<Item Name="SetUSB5AoTrigSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5AoTrigSource.vi"/>
			<Item Name="SetUSB5ClrAiFifo.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ClrAiFifo.vi"/>
			<Item Name="SetUSB5ClrAiTrigger.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ClrAiTrigger.vi"/>
			<Item Name="SetUSB5ClrAoFifo.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ClrAoFifo.vi"/>
			<Item Name="SetUSB5ClrAoTrigger.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ClrAoTrigger.vi"/>
			<Item Name="SetUSB5ClrDiFifo.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ClrDiFifo.vi"/>
			<Item Name="SetUSB5ClrDiTrigger.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ClrDiTrigger.vi"/>
			<Item Name="SetUSB5ClrDoFifo.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ClrDoFifo.vi"/>
			<Item Name="SetUSB5ClrDoTrigger.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ClrDoTrigger.vi"/>
			<Item Name="SetUSB5ClrTrigger.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ClrTrigger.vi"/>
			<Item Name="SetUSB5DiConvSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DiConvSource.vi"/>
			<Item Name="SetUSB5DiOneShotPoints.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DiOneShotPoints.vi"/>
			<Item Name="SetUSB5DiPreTrigPoints.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DiPreTrigPoints.vi"/>
			<Item Name="SetUSB5DiSampleMode.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DiSampleMode.vi"/>
			<Item Name="SetUSB5DiSampleRate.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DiSampleRate.vi"/>
			<Item Name="SetUSB5DiSoftTrig.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DiSoftTrig.vi"/>
			<Item Name="SetUSB5DiTrigSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DiTrigSource.vi"/>
			<Item Name="SetUSB5DoConvSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DoConvSource.vi"/>
			<Item Name="SetUSB5DoCycle.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DoCycle.vi"/>
			<Item Name="SetUSB5DoDataFifo.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DoDataFifo.vi"/>
			<Item Name="SetUSB5DoImmediately.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DoImmediately.vi"/>
			<Item Name="SetUSB5DoSampleMode.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DoSampleMode.vi"/>
			<Item Name="SetUSB5DoSampleRate.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DoSampleRate.vi"/>
			<Item Name="SetUSB5DoSoftTrig.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DoSoftTrig.vi"/>
			<Item Name="SetUSB5DoTrigSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DoTrigSource.vi"/>
			<Item Name="SetUSB5DoWaveCtrl.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5DoWaveCtrl.vi"/>
			<Item Name="SetUSB5ExtConvOutSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ExtConvOutSource.vi"/>
			<Item Name="SetUSB5ExtTrigOutSource.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5ExtTrigOutSource.vi"/>
			<Item Name="SetUSB5GlobalSoftTrig.vi" Type="VI" URL="../sub vi USB 5000/SetUSB5GlobalSoftTrig.vi"/>
			<Item Name="USB5CloseDevice.vi" Type="VI" URL="../sub vi USB 5000/USB5CloseDevice.vi"/>
			<Item Name="USB5GetAi.vi" Type="VI" URL="../sub vi USB 5000/USB5GetAi.vi"/>
			<Item Name="USB5GetDeviceSN.vi" Type="VI" URL="../sub vi USB 5000/USB5GetDeviceSN.vi"/>
			<Item Name="USB5GetDi.vi" Type="VI" URL="../sub vi USB 5000/USB5GetDi.vi"/>
			<Item Name="USB5OpenDevice.vi" Type="VI" URL="../sub vi USB 5000/USB5OpenDevice.vi"/>
		</Item>
		<Item Name="依赖关系" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="__closeStorageFromObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__closeStorageFromObject.vi"/>
				<Item Name="__convertUtcTime.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__convertUtcTime.vi"/>
				<Item Name="__createXmlString.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__createXmlString.vi"/>
				<Item Name="__getPropertyTypeObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/__getPropertyTypeObject.vi"/>
				<Item Name="__getPropertyTypeStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/__getPropertyTypeStorage.vi"/>
				<Item Name="__linkRefnumDefinitionObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__linkRefnumDefinitionObject.vi"/>
				<Item Name="__linkRefnumDefinitionStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__linkRefnumDefinitionStorage.vi"/>
				<Item Name="__loadPropEnum.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropEnum.vi"/>
				<Item Name="__loadPropErrFilter.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropErrFilter.vi"/>
				<Item Name="__loadPropFloat32.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropFloat32.vi"/>
				<Item Name="__loadPropFloat64.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropFloat64.vi"/>
				<Item Name="__loadPropInt16.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropInt16.vi"/>
				<Item Name="__loadPropInt32.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropInt32.vi"/>
				<Item Name="__loadPropRef.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropRef.vi"/>
				<Item Name="__loadPropRefList.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropRefList.vi"/>
				<Item Name="__loadPropString.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropString.vi"/>
				<Item Name="__loadPropTime.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropTime.vi"/>
				<Item Name="__loadPropUInt8.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__loadPropUInt8.vi"/>
				<Item Name="__queryObjects.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__queryObjects.vi"/>
				<Item Name="__saveDdtAttrs.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/__saveDdtAttrs.vi"/>
				<Item Name="__savePropEnum.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropEnum.vi"/>
				<Item Name="__savePropErrFilter.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropErrFilter.vi"/>
				<Item Name="__savePropFloat32.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropFloat32.vi"/>
				<Item Name="__savePropFloat64.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropFloat64.vi"/>
				<Item Name="__savePropInt16.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropInt16.vi"/>
				<Item Name="__savePropInt32.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropInt32.vi"/>
				<Item Name="__savePropRef.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropRef.vi"/>
				<Item Name="__savePropRefList.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropRefList.vi"/>
				<Item Name="__savePropString.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropString.vi"/>
				<Item Name="__savePropTime.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropTime.vi"/>
				<Item Name="__savePropUInt8.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__savePropUInt8.vi"/>
				<Item Name="__setErrSource.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/__setErrSource.vi"/>
				<Item Name="_checkInstAttrError.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_checkInstAttrError.vi"/>
				<Item Name="_closeDataStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_closeDataStorage.vi"/>
				<Item Name="_commitObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_commitObject.vi"/>
				<Item Name="_commitStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_commitStorage.vi"/>
				<Item Name="_commitTransaction.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_commitTransaction.vi"/>
				<Item Name="_createExplicitChildObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_createExplicitChildObject.vi"/>
				<Item Name="_createObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_createObject.vi"/>
				<Item Name="_createOrGetByNameExplicitChildObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_createOrGetByNameExplicitChildObject.vi"/>
				<Item Name="_createOrGetExplicitChildObject.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_createOrGetExplicitChildObject.vi"/>
				<Item Name="_defaultFilePath.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_defaultFilePath.vi"/>
				<Item Name="_findOpenStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_findOpenStorage.vi"/>
				<Item Name="_getChannelNameFromDDT.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_getChannelNameFromDDT.vi"/>
				<Item Name="_getObjDefByName.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_getObjDefByName.vi"/>
				<Item Name="_getPluginListFromUsi.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_getPluginListFromUsi.vi"/>
				<Item Name="_getPluginListFromUsiEx.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_getPluginListFromUsiEx.vi"/>
				<Item Name="_getPropDefByName.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_getPropDefByName.vi"/>
				<Item Name="_getPropertyType.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_getPropertyType.vi"/>
				<Item Name="_internalProps.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_internalProps.ctl"/>
				<Item Name="_isTdmDataStructure.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_isTdmDataStructure.vi"/>
				<Item Name="_L_localizedStrings.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_L_localizedStrings.vi"/>
				<Item Name="_L_NodeNames.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_L_NodeNames.vi"/>
				<Item Name="_L_stringTable.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_L_stringTable.vi"/>
				<Item Name="_loadObjectDefinitions.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_loadObjectDefinitions.vi"/>
				<Item Name="_loadProperty.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_loadProperty.vi"/>
				<Item Name="_loadPropertyDefinitions.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_loadPropertyDefinitions.vi"/>
				<Item Name="_mapTdmObjectTypes.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_mapTdmObjectTypes.vi"/>
				<Item Name="_mapTdmPropertyNames.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_mapTdmPropertyNames.vi"/>
				<Item Name="_openDataStorage.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_openDataStorage.vi"/>
				<Item Name="_openFunction.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_openFunction.ctl"/>
				<Item Name="_openStorageWithRootAutoDetect.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_openStorageWithRootAutoDetect.vi"/>
				<Item Name="_openStorageWithRootNoPluginCheck.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_openStorageWithRootNoPluginCheck.vi"/>
				<Item Name="_openWithRoot.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_openWithRoot.vi"/>
				<Item Name="_prepAOW.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_prepAOW.vi"/>
				<Item Name="_prepDDT.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_prepDDT.vi"/>
				<Item Name="_saveDDT.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_saveDDT.vi"/>
				<Item Name="_saveDdtAttributes.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_saveDdtAttributes.vi"/>
				<Item Name="_saveFloat64Channel.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_saveFloat64Channel.vi"/>
				<Item Name="_saveProperty.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_saveProperty.vi"/>
				<Item Name="_saveWaveformDdt.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_saveWaveformDdt.vi"/>
				<Item Name="_sortStorageFormat.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/utility/_sortStorageFormat.vi"/>
				<Item Name="_stringsToBeTranslated.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_stringsToBeTranslated.ctl"/>
				<Item Name="_TDM_DATA_MODEL.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/_TDM_DATA_MODEL.vi"/>
				<Item Name="_WaveformProperties.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_WaveformProperties.vi"/>
				<Item Name="_wf_attributes.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/_wf_attributes.ctl"/>
				<Item Name="Analog to Digital.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DWDT.llb/Analog to Digital.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="CloseDataObjectRefnum.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/CloseDataObjectRefnum.vi"/>
				<Item Name="CloseDataStorageRefnum.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/CloseDataStorageRefnum.vi"/>
				<Item Name="dataModel.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/dataModel.ctl"/>
				<Item Name="Dflt Data Dir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Dflt Data Dir.vi"/>
				<Item Name="DTbl Analog to Digital.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DTblOps.llb/DTbl Analog to Digital.vi"/>
				<Item Name="DTbl Compress Digital.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DTblOps.llb/DTbl Compress Digital.vi"/>
				<Item Name="DTbl Digital Size.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DTblOps.llb/DTbl Digital Size.vi"/>
				<Item Name="DU64_U32AddWithOverflow.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/TSOps.llb/DU64_U32AddWithOverflow.vi"/>
				<Item Name="DU64_U32SubtractWithBorrow.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/TSOps.llb/DU64_U32SubtractWithBorrow.vi"/>
				<Item Name="DWDT Analog to Digital.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DWDTOps.llb/DWDT Analog to Digital.vi"/>
				<Item Name="Dynamic To Waveform Array.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/transition.llb/Dynamic To Waveform Array.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="ErrorOut.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/xStorage/xStorageSupp/ErrorOut.vi"/>
				<Item Name="ex_convertXDim.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ExFile.llb/ex_convertXDim.vi"/>
				<Item Name="ex_GetAllExpressAttribsPlus.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/transition.llb/ex_GetAllExpressAttribsPlus.vi"/>
				<Item Name="ex_GetDefaultUnits.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ExFile.llb/ex_GetDefaultUnits.vi"/>
				<Item Name="ex_SetAllExpressAttribs.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/transition.llb/ex_SetAllExpressAttribs.vi"/>
				<Item Name="ex_SetExpAttribsAndT0.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/transition.llb/ex_SetExpAttribsAndT0.vi"/>
				<Item Name="ex_WaveformAttribs.ctl" Type="VI" URL="/&lt;vilib&gt;/express/express shared/transition.llb/ex_WaveformAttribs.ctl"/>
				<Item Name="ex_WaveformAttribsPlus.ctl" Type="VI" URL="/&lt;vilib&gt;/express/express shared/transition.llb/ex_WaveformAttribsPlus.ctl"/>
				<Item Name="Get File Extension.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Get File Extension.vi"/>
				<Item Name="Get Object Info.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/Get Object Info.vi"/>
				<Item Name="Get Property Type.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/Get Property Type.vi"/>
				<Item Name="I128 Timestamp.ctl" Type="VI" URL="/&lt;vilib&gt;/Waveform/TSOps.llb/I128 Timestamp.ctl"/>
				<Item Name="List DataPlugins.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/utility/List DataPlugins.vi"/>
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="NI_MABase.lvlib" Type="Library" URL="/&lt;vilib&gt;/measure/NI_MABase.lvlib"/>
				<Item Name="ParseXMLParams.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/lvStorage.llb/ParseXMLParams.vi"/>
				<Item Name="SetT0.vi" Type="VI" URL="/&lt;vilib&gt;/express/express signal manip/GetorSetDDTAttributes/Set DDT Attributes/SetT0.vi"/>
				<Item Name="specialProperties.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/specialProperties.ctl"/>
				<Item Name="Timestamp Add.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/TSOps.llb/Timestamp Add.vi"/>
				<Item Name="Timestamp Subtract.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/TSOps.llb/Timestamp Subtract.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="usiDataType.ctl" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_EditUserDefinedProperties/usiDataType.ctl"/>
				<Item Name="usiOverwriteOptions.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiOverwriteOptions.ctl"/>
				<Item Name="usiPluginInformation.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/utility/usiPluginInformation.ctl"/>
				<Item Name="usiPropDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiPropDef.ctl"/>
				<Item Name="usiSequenceRepresentation.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiSequenceRepresentation.ctl"/>
				<Item Name="usiTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiTypeDef.ctl"/>
				<Item Name="usiValueFlags.ctl" Type="VI" URL="/&lt;vilib&gt;/Platform/storage/Storage.llb/usiValueFlags.ctl"/>
				<Item Name="Waveform Array To Dynamic.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/transition.llb/Waveform Array To Dynamic.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
			</Item>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
			<Item Name="lvStorage.dll" Type="Document" URL="lvStorage.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="USB5000.dll" Type="Document" URL="USB5000.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
		</Item>
		<Item Name="程序生成规范" Type="Build"/>
	</Item>
</Project>
