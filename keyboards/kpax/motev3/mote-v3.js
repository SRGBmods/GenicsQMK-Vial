export function Name() { return "MOTE-V3"; }
export function Version() { return "1.1.9"; }
export function VendorId() { return 0x1981; }
export function ProductId() { return 0x1988; }
export function Publisher() { return "KPAX"; }
export function Documentation(){ return "qmk/srgbmods-qmk-firmware"; }
export function DeviceType() { return "keyboard"; }
export function ConflictingProcesses() { return ["VIA.exe"]; }
export function Size() { return [1, 1]; }
export function DefaultPosition(){return [10, 100]; }
export function DefaultScale(){return 1.0;}
/* global
shutdownMode:readonly
shutdownColor:readonly
LightingMode:readonly
forcedColor:readonly
*/
export function ControllableParameters() {
	return [
		{"property":"shutdownMode", "group":"lighting", "label":"Shutdown Mode", "type":"combobox", "values":["SignalRGB", "Hardware"], "default":"SignalRGB"},
		{"property":"shutdownColor", "group":"lighting", "label":"Shutdown Color", "min":"0", "max":"360", "type":"color", "default":"#000000"},
		{"property":"LightingMode", "group":"lighting", "label":"Lighting Mode", "type":"combobox", "values":["Canvas", "Forced"], "default":"Canvas"},
		{"property":"forcedColor", "group":"lighting", "label":"Forced Color", "min":"0", "max":"360", "type":"color", "default":"#009bde"},
	];
}

//Plugin Version: Built for Protocol V1.0.5

const vKeys = [

];

const vKeyNames = [

];

const vKeyPositions = [

];

const Keyboard = {
	Left : {
		devicename: "Left Side",
		ledids: [
			0, 1, 2, 3,	4, 5,
            6, 7, 8, 9, 10, 11,
			12,13,14,15,16,17,
            18,19,20,21,22,23,
                        24,25,26,27,
            28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,
		],
		lednames: [
			"Esc",   "1",  "2", "3", "4", "5",
			"Tab",   "Q",  "W", "E", "R", "T",
			"Shift", "A",  "S", "D", "F", "G",
            "Ctrl",  "Z",  "X", "C", "V", "B",
                                   "Left Alt", "Space","Apps","AudioMute",
            "ug1", "ug2","ug3","ug4","ug5","ug6","ug7","ug8","ug9","ug10","ug11","ug12","ug13","ug14","ug15","ug16","ug17","ug18","ug19","ug20","ug21","ug22",

		],
		ledpos:	[
			[0, 0], [1, 0], [2, 0], [3, 0],[4, 0],[5, 0],
			[0, 1], [1, 1], [2, 1], [3, 1],[4, 1],[5, 1],
			[0, 2], [1, 2], [2, 2], [3, 2],[4, 2],[5, 2],
            [0, 3], [1, 3], [2, 3], [3, 3],[4, 3],[5, 3],
			                               [4, 4],[5, 4],[6, 4],[6, 3],
            [4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],

		],
		width: 7,
		height: 5,
		image: Image()
	},
	Right : {
		devicename: "Right Side",
		ledids: [
			  55,54,53,52,51,50,
			  61,60,59,58,57,56,
			  67,66,65,64,63,62,
              73,72,71,70,69,68,
        77,76,75,74,
        78, 79, 80, 81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,

		],
		lednames: [
			"right 6","right 5","right 4", "right 3", "right 2", "right 1",
			"right 12","right 11","right 10", "right 9", "right 8", "right 7",
			"right 18","right 17","right 16", "right 15", "right 14", "right 13",
            "right 24","right 23","right 22", "right 21", "right 20", "right 19",
            "right 28", "right 27", "right 26", "right 25",
            "right 29","right 30","right 31", "right 32", "right 33", "right 34","right 35","right 36","right 37","right 38","right 39","right 40","right 41","right 42","right 43","right 44","right 45","right 46","right 47","right 48","right 49","right 50",
		],
		ledpos:	[
			 [5, 0], [4, 0],[3, 0], [2, 0],[1, 0],[0, 0],
			 [5, 1], [4, 1],[3, 1], [2, 1],[1, 1],[0, 1],
			 [5, 2], [4, 2],[3, 2], [2, 2],[1, 2],[0, 2],
             [5, 3], [4, 3],[3, 3], [2, 3],[1, 3],[0, 3],
             [6, 3],[6, 4],[5, 4],[4, 4],
            [4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],[4, 4],
		],
		width: 7,
		height: 5,
		image: Image()
	}
};

let LEDCount = 0;
let IsViaKeyboard = false;
const MainlineQMKFirmware = 1;
const VIAFirmware = 2;
const PluginProtocolVersion = "1.0.5";

export function Initialize() {
	requestFirmwareType();
	requestQMKVersion();
	requestSignalRGBProtocolVersion();
	requestUniqueIdentifier();
	requestTotalLeds();
	effectEnable();

	device.createSubdevice("LeftSide");
	device.setSubdeviceName("LeftSide", `${Keyboard.Left.devicename}`);
	device.setSubdeviceImage("LeftSide", Keyboard.Left.image);
	device.setSubdeviceSize("LeftSide", Keyboard.Left.width, Keyboard.Left.height);
	device.setSubdeviceLeds("LeftSide", Keyboard.Left.lednames, Keyboard.Left.ledpos);

	device.createSubdevice("RightSide");
	device.setSubdeviceName("RightSide", `${Keyboard.Right.devicename}`);
	device.setSubdeviceImage("RightSide", Keyboard.Right.image);
	device.setSubdeviceSize("RightSide", Keyboard.Right.width, Keyboard.Right.height);
	device.setSubdeviceLeds("RightSide", Keyboard.Right.lednames, Keyboard.Right.ledpos);

}

export function Render() {
	sendColors();
}

export function Shutdown(SystemSuspending) {

	if(SystemSuspending) {
		sendColors("#000000"); // Go Dark on System Sleep/Shutdown
	} else {
		if (shutdownMode === "SignalRGB") {
			sendColors(shutdownColor);
		} else {
			effectDisable();
		}
	}

}

function commandHandler() {
	const readCounts = [];

	do {
		const returnpacket = device.read([0x00], 32, 10);
		processCommands(returnpacket);

		readCounts.push(device.getLastReadSize());

		// Extra Read to throw away empty packets from Via
		// Via always sends a second packet with the same Command Id.
		if(IsViaKeyboard) {
			device.read([0x00], 32, 10);
		}
	}
	while(device.getLastReadSize() > 0);

}

function processCommands(data) {
	switch(data[1]) {
	case 0x21:
		returnQMKVersion(data);
		break;
	case 0x22:
		returnSignalRGBProtocolVersion(data);
		break;
	case 0x23:
		returnUniqueIdentifier(data);
		break;
	case 0x24:
		sendColors();
		break;
	case 0x27:
		returnTotalLeds(data);
		break;
	case 0x28:
		returnFirmwareType(data);
		break;
	}
}

function requestQMKVersion() //Check the version of QMK Firmware that the keyboard is running
{
	device.write([0x00, 0x21], 32);
	device.pause(30);
	commandHandler();
}

function returnQMKVersion(data) {
	const QMKVersionByte1 = data[2];
	const QMKVersionByte2 = data[3];
	const QMKVersionByte3 = data[4];
	device.log("QMK Version: " + QMKVersionByte1 + "." + QMKVersionByte2 + "." + QMKVersionByte3);
	device.log("QMK SRGB Plugin Version: "+ Version());
	device.pause(30);
}

function requestSignalRGBProtocolVersion() //Grab the version of the SignalRGB Protocol the keyboard is running
{
	device.write([0x00, 0x22], 32);
	device.pause(30);
	commandHandler();
}

function returnSignalRGBProtocolVersion(data) {
	const ProtocolVersionByte1 = data[2];
	const ProtocolVersionByte2 = data[3];
	const ProtocolVersionByte3 = data[4];

	const SignalRGBProtocolVersion = ProtocolVersionByte1 + "." + ProtocolVersionByte2 + "." + ProtocolVersionByte3;
	device.log(`SignalRGB Protocol Version: ${SignalRGBProtocolVersion}`);


	if(PluginProtocolVersion !== SignalRGBProtocolVersion) {
		device.notify("Unsupported Protocol Version", `This plugin is intended for SignalRGB Protocol version ${PluginProtocolVersion}. This device is version: ${SignalRGBProtocolVersion}`, 2, "Documentation");
	}

	device.pause(30);
}

function requestUniqueIdentifier() //Grab the unique identifier for this keyboard model
{
	if(device.write([0x00, 0x23], 32) === -1) {
		device.notify("Unsupported Firmware", "This device is not running SignalRGB-compatible firmware. Click the Documentation button to learn more.", 3, "Documentation");
	}

	device.pause(30);
	commandHandler();
}


function returnUniqueIdentifier(data) {
	const UniqueIdentifierByte1 = data[2];
	const UniqueIdentifierByte2 = data[3];
	const UniqueIdentifierByte3 = data[4];

	if(!(UniqueIdentifierByte1 === 0 && UniqueIdentifierByte2 === 0 && UniqueIdentifierByte3 === 0)) {
		device.log("Unique Device Identifier: " + UniqueIdentifierByte1 + UniqueIdentifierByte2 + UniqueIdentifierByte3);
	}

	device.pause(30);
}

function requestTotalLeds() //Calculate total number of LEDs
{
	device.write([0x00, 0x27], 32);
	device.pause(30);
	commandHandler();
}

function returnTotalLeds(data) {
	LEDCount = data[2];
	device.log("Device Total LED Count: " + LEDCount);
	device.pause(30);
}

function requestFirmwareType() {
	device.write([0x00, 0x28], 32);
	device.pause(30);
	commandHandler();
}

function returnFirmwareType(data) {
	const FirmwareTypeByte = data[2];

	if(!(FirmwareTypeByte === MainlineQMKFirmware || FirmwareTypeByte === VIAFirmware)) {
		device.notify("Unsupported Firmware", "Click the Documentation button to learn more.", 3, "Documentation");
	}

	if(FirmwareTypeByte === MainlineQMKFirmware) {
		IsViaKeyboard = false;
		device.log("Firmware Type: Mainline");
	}

	if(FirmwareTypeByte === VIAFirmware) {
		IsViaKeyboard = true;
		device.log("Firmware Type: VIA");
	}

	device.pause(30);
}

function effectEnable() //Enable the SignalRGB Effect Mode
{
	device.write([0x00, 0x25], 32);
	device.pause(30);
}

function effectDisable() //Revert to Hardware Mode
{
	device.write([0x00, 0x26], 32);
	device.pause(30);
}

function createSolidColorArray(color) {
	const rgbdata = new Array(vKeys.length * 3).fill(0);

	for(let iIdx = 0; iIdx < vKeys.length; iIdx++) {
		const iLedIdx = vKeys[iIdx] * 3;
		rgbdata[iLedIdx] = color[0];
		rgbdata[iLedIdx+1] = color[1];
		rgbdata[iLedIdx+2] = color[2];
	}

	return rgbdata;
}

function grabColors(overrideColor) {
	if(overrideColor) {
		return createSolidColorArray(hexToRgb(overrideColor));
	} else if (LightingMode === "Forced") {
		return createSolidColorArray(hexToRgb(forcedColor));
	}

	const rgbdata = new Array(vKeys.length * 3).fill(0);

	for(let iIdx = 0; iIdx < vKeys.length; iIdx++) {
		const iPxX = vKeyPositions[iIdx][0];
		const iPxY = vKeyPositions[iIdx][1];
		const color = device.color(iPxX, iPxY);

		const iLedIdx = vKeys[iIdx] * 3;
		rgbdata[iLedIdx] = color[0];
		rgbdata[iLedIdx+1] = color[1];
		rgbdata[iLedIdx+2] = color[2];
	}

	return rgbdata;
}

function sendColors(overrideColor) {
	const rgbdata = grabColors(overrideColor);

	const LedsPerPacket = 9;
	let BytesSent = 0;
	let BytesLeft = rgbdata.length;

	while(BytesLeft > 0) {
		const BytesToSend = Math.min(LedsPerPacket * 3, BytesLeft);
		StreamLightingData(Math.floor(BytesSent / 3), rgbdata.splice(0, BytesToSend));

		BytesLeft -= BytesToSend;
		BytesSent += BytesToSend;
	}
}

function StreamLightingData(StartLedIdx, RGBData) {
	const packet = [0x00, 0x24, StartLedIdx, Math.floor(RGBData.length / 3)].concat(RGBData);
	device.write(packet, 33);
}

function hexToRgb(hex) {
	const result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
	const colors = [];
	colors[0] = parseInt(result[1], 16);
	colors[1] = parseInt(result[2], 16);
	colors[2] = parseInt(result[3], 16);

	return colors;
}

export function Validate(endpoint) {
	return endpoint.interface === 1;
}

export function Image() {
	return "https://i.imgur.com/9Nxkeun.png";
}
