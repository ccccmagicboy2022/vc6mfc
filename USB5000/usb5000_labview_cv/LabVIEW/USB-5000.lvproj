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
		<Item Name="example" Type="Folder">
			<Item Name="ai_continuous_and_ao_waveform_pc_infinite.vi" Type="VI" URL="../example/ai_continuous_and_ao_waveform_pc_infinite.vi"/>
			<Item Name="ai_continuous_full.vi" Type="VI" URL="../example/ai_continuous_full.vi"/>
			<Item Name="ai_continuous_lite.vi" Type="VI" URL="../example/ai_continuous_lite.vi"/>
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
				<Item Name="Analog to Digital.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DWDT.llb/Analog to Digital.vi"/>
				<Item Name="DTbl Analog to Digital.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DTblOps.llb/DTbl Analog to Digital.vi"/>
				<Item Name="DTbl Compress Digital.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DTblOps.llb/DTbl Compress Digital.vi"/>
				<Item Name="DTbl Digital Size.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DTblOps.llb/DTbl Digital Size.vi"/>
				<Item Name="DWDT Analog to Digital.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DWDTOps.llb/DWDT Analog to Digital.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="NI_MABase.lvlib" Type="Library" URL="/&lt;vilib&gt;/measure/NI_MABase.lvlib"/>
			</Item>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
			<Item Name="USB5000.dll" Type="Document" URL="USB5000.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
		</Item>
		<Item Name="程序生成规范" Type="Build"/>
	</Item>
</Project>
