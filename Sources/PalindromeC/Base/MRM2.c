#include "MRM.h"
uint8_t* readAddressMRM32For32(uint8_t mrmByte) {
	uint8_t mod = readFirst2Bit(mrmByte);
	uint8_t base = readLast3Bit(mrmByte);
	if (mod == 3) {
		return (uint8_t*)register32(base);
	}
	LOG("MRM(m: %d, b: %d)", mod, base);
	switch (base) {
		case 0: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EAX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EAX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EAX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 1: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_ECX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_ECX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_ECX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 2: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EDX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EDX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EDX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 3: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EBX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EBX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EBX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 4: {
			uint8_t sibByte = read8u();
			uint8_t scaleByte = readFirst2Bit(sibByte);
			uint8_t indexByte = readMiddle3Bit(sibByte);
			uint8_t baseByte = readLast3Bit(sibByte);
			int32_t shift = 0;
			LOG("SIB(b: %d, i: %d, s: %d)", baseByte, indexByte, scaleByte);
			switch (indexByte) {
				case 4: {
					shift = 0;;
				}
				break;
				default:
				{
					switch (scaleByte) {
						case 0: {
							shift = *register32(indexByte) * 1;
						}
						break;
						case 1: {
							shift = *register32(indexByte) * 2;
						}
						break;
						case 2: {
							shift = *register32(indexByte) * 4;
						}
						break;
						case 3: {
							shift = *register32(indexByte) * 8;
						}
						break;
						default:
						shift = 0;
					}
				} break;
			}
			switch (baseByte) {
				case 0: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EAX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EAX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EAX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 1: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_ECX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_ECX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_ECX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 2: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EDX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EDX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EDX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 3: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EBX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EBX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EBX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 4: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_SS) + *register32(BR_ESP_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_SS) + *register32(BR_ESP_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_SS) + *register32(BR_ESP_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 5: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + read32() + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_SS) + *register32(BR_EBP_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_SS) + *register32(BR_EBP_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 6: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_ESI_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_ESI_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_ESI_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 7: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EDI_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EDI_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EDI_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 5: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + read32();
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register32(BR_EBP_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register32(BR_EBP_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 6: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_ESI_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_ESI_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_ESI_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 7: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EDI_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EDI_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EDI_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		default:
		return 0;
	}
}
uint8_t* readAddressMRM32For16(uint8_t mrmByte) {
	uint8_t mod = readFirst2Bit(mrmByte);
	uint8_t base = readLast3Bit(mrmByte);
	if (mod == 3) {
		return (uint8_t*)register16(base);
	}
	LOG("MRM(m: %d, b: %d)", mod, base);
	switch (base) {
		case 0: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EAX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EAX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EAX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 1: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_ECX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_ECX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_ECX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 2: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EDX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EDX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EDX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 3: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EBX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EBX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EBX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 4: {
			uint8_t sibByte = read8u();
			uint8_t scaleByte = readFirst2Bit(sibByte);
			uint8_t indexByte = readMiddle3Bit(sibByte);
			uint8_t baseByte = readLast3Bit(sibByte);
			int32_t shift = 0;
			LOG("SIB(b: %d, i: %d, s: %d)", baseByte, indexByte, scaleByte);
			switch (indexByte) {
				case 4: {
					shift = 0;;
				}
				break;
				default:
				{
					switch (scaleByte) {
						case 0: {
							shift = *register32(indexByte) * 1;
						}
						break;
						case 1: {
							shift = *register32(indexByte) * 2;
						}
						break;
						case 2: {
							shift = *register32(indexByte) * 4;
						}
						break;
						case 3: {
							shift = *register32(indexByte) * 8;
						}
						break;
						default:
						shift = 0;
					}
				} break;
			}
			switch (baseByte) {
				case 0: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EAX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EAX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EAX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 1: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_ECX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_ECX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_ECX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 2: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EDX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EDX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EDX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 3: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EBX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EBX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EBX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 4: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_SS) + *register32(BR_ESP_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_SS) + *register32(BR_ESP_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_SS) + *register32(BR_ESP_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 5: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + read32() + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_SS) + *register32(BR_EBP_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_SS) + *register32(BR_EBP_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 6: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_ESI_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_ESI_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_ESI_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 7: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EDI_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EDI_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EDI_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 5: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + read32();
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register32(BR_EBP_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register32(BR_EBP_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 6: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_ESI_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_ESI_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_ESI_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 7: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EDI_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EDI_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EDI_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		default:
		return 0;
	}
}
uint8_t* readAddressMRM32For8(uint8_t mrmByte) {
	uint8_t mod = readFirst2Bit(mrmByte);
	uint8_t base = readLast3Bit(mrmByte);
	if (mod == 3) {
		return (uint8_t*)register8(base);
	}
	LOG("MRM(m: %d, b: %d)", mod, base);
	switch (base) {
		case 0: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EAX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EAX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EAX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 1: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_ECX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_ECX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_ECX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 2: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EDX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EDX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EDX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 3: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EBX_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EBX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EBX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 4: {
			uint8_t sibByte = read8u();
			uint8_t scaleByte = readFirst2Bit(sibByte);
			uint8_t indexByte = readMiddle3Bit(sibByte);
			uint8_t baseByte = readLast3Bit(sibByte);
			int32_t shift = 0;
			LOG("SIB(b: %d, i: %d, s: %d)", baseByte, indexByte, scaleByte);
			switch (indexByte) {
				case 4: {
					shift = 0;;
				}
				break;
				default:
				{
					switch (scaleByte) {
						case 0: {
							shift = *register32(indexByte) * 1;
						}
						break;
						case 1: {
							shift = *register32(indexByte) * 2;
						}
						break;
						case 2: {
							shift = *register32(indexByte) * 4;
						}
						break;
						case 3: {
							shift = *register32(indexByte) * 8;
						}
						break;
						default:
						shift = 0;
					}
				} break;
			}
			switch (baseByte) {
				case 0: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EAX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EAX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EAX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 1: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_ECX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_ECX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_ECX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 2: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EDX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EDX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EDX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 3: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EBX_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EBX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EBX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 4: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_SS) + *register32(BR_ESP_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_SS) + *register32(BR_ESP_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_SS) + *register32(BR_ESP_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 5: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + read32() + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_SS) + *register32(BR_EBP_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_SS) + *register32(BR_EBP_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 6: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_ESI_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_ESI_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_ESI_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 7: {
					switch (mod) {
						case 0: {
							return memWithReplace(SR_DS) + *register32(BR_EDI_F) + shift;
						}
						break;
						case 1: {
							return memWithReplace(SR_DS) + *register32(BR_EDI_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return memWithReplace(SR_DS) + *register32(BR_EDI_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 5: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + read32();
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register32(BR_EBP_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register32(BR_EBP_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 6: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_ESI_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_ESI_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_ESI_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 7: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register32(BR_EDI_F);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register32(BR_EDI_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register32(BR_EDI_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		default:
		return 0;
	}
}
int32_t effectiveAddressMRM32For32(uint8_t mrmByte) {
	uint8_t mod = readFirst2Bit(mrmByte);
	uint8_t base = readLast3Bit(mrmByte);
	if (mod == 3) {
		return 0;
	}
	LOG("MRM(m: %d, b: %d)", mod, base);
	switch (base) {
		case 0: {
			switch (mod) {
				case 0: {
					return   *register32(BR_EAX_F);
				}
				break;
				case 1: {
					return   *register32(BR_EAX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register32(BR_EAX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 1: {
			switch (mod) {
				case 0: {
					return   *register32(BR_ECX_F);
				}
				break;
				case 1: {
					return   *register32(BR_ECX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register32(BR_ECX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 2: {
			switch (mod) {
				case 0: {
					return   *register32(BR_EDX_F);
				}
				break;
				case 1: {
					return   *register32(BR_EDX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register32(BR_EDX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 3: {
			switch (mod) {
				case 0: {
					return   *register32(BR_EBX_F);
				}
				break;
				case 1: {
					return   *register32(BR_EBX_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register32(BR_EBX_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 4: {
			uint8_t sibByte = read8u();
			uint8_t scaleByte = readFirst2Bit(sibByte);
			uint8_t indexByte = readMiddle3Bit(sibByte);
			uint8_t baseByte = readLast3Bit(sibByte);
			int32_t shift = 0;
			LOG("SIB(b: %d, i: %d, s: %d)", baseByte, indexByte, scaleByte);
			switch (indexByte) {
				case 4: {
					shift = 0;;
				}
				break;
				default:
				{
					switch (scaleByte) {
						case 0: {
							shift = *register32(indexByte) * 1;
						}
						break;
						case 1: {
							shift = *register32(indexByte) * 2;
						}
						break;
						case 2: {
							shift = *register32(indexByte) * 4;
						}
						break;
						case 3: {
							shift = *register32(indexByte) * 8;
						}
						break;
						default:
						shift = 0;
					}
				} break;
			}
			switch (baseByte) {
				case 0: {
					switch (mod) {
						case 0: {
							return   *register32(BR_EAX_F) + shift;
						}
						break;
						case 1: {
							return   *register32(BR_EAX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return   *register32(BR_EAX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 1: {
					switch (mod) {
						case 0: {
							return   *register32(BR_ECX_F) + shift;
						}
						break;
						case 1: {
							return   *register32(BR_ECX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return   *register32(BR_ECX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 2: {
					switch (mod) {
						case 0: {
							return   *register32(BR_EDX_F) + shift;
						}
						break;
						case 1: {
							return   *register32(BR_EDX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return   *register32(BR_EDX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 3: {
					switch (mod) {
						case 0: {
							return   *register32(BR_EBX_F) + shift;
						}
						break;
						case 1: {
							return   *register32(BR_EBX_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return   *register32(BR_EBX_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 4: {
					switch (mod) {
						case 0: {
							return   *register32(BR_ESP_F) + shift;
						}
						break;
						case 1: {
							return   *register32(BR_ESP_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return   *register32(BR_ESP_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 5: {
					switch (mod) {
						case 0: {
							return   read32() + shift;
						}
						break;
						case 1: {
							return   *register32(BR_EBP_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return   *register32(BR_EBP_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 6: {
					switch (mod) {
						case 0: {
							return   *register32(BR_ESI_F) + shift;
						}
						break;
						case 1: {
							return   *register32(BR_ESI_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return   *register32(BR_ESI_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				case 7: {
					switch (mod) {
						case 0: {
							return   *register32(BR_EDI_F) + shift;
						}
						break;
						case 1: {
							return   *register32(BR_EDI_F) + shift + ((int16_t)read8());
						}
						break;
						case 2: {
							return   *register32(BR_EDI_F) + shift + read32();
						}
						break;
						default:
						return 0;
					}
					;
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 5: {
			switch (mod) {
				case 0: {
					return   read32();
				}
				break;
				case 1: {
					return   *register32(BR_EBP_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register32(BR_EBP_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 6: {
			switch (mod) {
				case 0: {
					return   *register32(BR_ESI_F);
				}
				break;
				case 1: {
					return   *register32(BR_ESI_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register32(BR_ESI_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 7: {
			switch (mod) {
				case 0: {
					return   *register32(BR_EDI_F);
				}
				break;
				case 1: {
					return   *register32(BR_EDI_F) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register32(BR_EDI_F) + read32();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		default:
		return 0;
	}
}
int16_t effectiveAddressMRM16For16(uint8_t mrmByte) {
	uint8_t mod = readFirst2Bit(mrmByte);
	uint8_t base = readLast3Bit(mrmByte);
	if (mod == 3) {
		return 0;
	}
	LOG("MRM(m: %d, b: %d)", mod, base);
	switch (base) {
		case 0: {
			switch (mod) {
				case 0: {
					return   *register16(BR_BX) + *register16(BR_SI);
				}
				break;
				case 1: {
					return   *register16(BR_BX) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register16(BR_BX) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 1: {
			switch (mod) {
				case 0: {
					return   *register16(BR_BX) + *register16(BR_DI);
				}
				break;
				case 1: {
					return   *register16(BR_BX) + *register16(BR_DI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register16(BR_BX) + *register16(BR_DI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 2: {
			switch (mod) {
				case 0: {
					return   *register16(BR_BP) + *register16(BR_SI);
				}
				break;
				case 1: {
					return   *register16(BR_BP) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register16(BR_BP) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 3: {
			switch (mod) {
				case 0: {
					return   *register16(BR_BP) + *register16(BR_SI);
				}
				break;
				case 1: {
					return   *register16(BR_BP) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register16(BR_BP) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 4: {
			switch (mod) {
				case 0: {
					return   *register16(BR_SI);
				}
				break;
				case 1: {
					return   *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 5: {
			switch (mod) {
				case 0: {
					return   *register16(BR_DI);
				}
				break;
				case 1: {
					return   *register16(BR_DI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register16(BR_DI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 6: {
			switch (mod) {
				case 0: {
					return   read16();
				}
				break;
				case 1: {
					return   *register16(BR_BP) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register16(BR_BP) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 7: {
			switch (mod) {
				case 0: {
					return   *register16(BR_BX);
				}
				break;
				case 1: {
					return   *register16(BR_BX) + ((int16_t)read8());
				}
				break;
				case 2: {
					return   *register16(BR_BX) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		default:
		return 0;
	}
}
uint8_t* readAddressMRM16For32(uint8_t mrmByte) {
	uint8_t mod = readFirst2Bit(mrmByte);
	uint8_t base = readLast3Bit(mrmByte);
	if (mod == 3) {
		return (uint8_t*)register32(base);
	}
	LOG("MRM(m: %d, b: %d)", mod, base);
	switch (base) {
		case 0: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 1: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_DI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_DI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_DI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 2: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 3: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 4: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 5: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_DI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_DI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_DI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 6: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + read16();
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 7: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_BX);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		default:
		return 0;
	}
}
uint8_t* readAddressMRM16For16(uint8_t mrmByte) {
	uint8_t mod = readFirst2Bit(mrmByte);
	uint8_t base = readLast3Bit(mrmByte);
	if (mod == 3) {
		return (uint8_t*)register16(base);
	}
	LOG("MRM(m: %d, b: %d)", mod, base);
	switch (base) {
		case 0: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 1: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_DI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_DI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_DI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 2: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 3: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 4: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 5: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_DI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_DI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_DI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 6: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + read16();
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 7: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_BX);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		default:
		return 0;
	}
}
uint8_t* readAddressMRM16For8(uint8_t mrmByte) {
	uint8_t mod = readFirst2Bit(mrmByte);
	uint8_t base = readLast3Bit(mrmByte);
	if (mod == 3) {
		return (uint8_t*)register8(base);
	}
	LOG("MRM(m: %d, b: %d)", mod, base);
	switch (base) {
		case 0: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 1: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_DI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_DI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + *register16(BR_DI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 2: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 3: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 4: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_SI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_SI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_SI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 5: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_DI);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_DI) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_DI) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 6: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + read16();
				}
				break;
				case 1: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_SS) + *register16(BR_BP) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		case 7: {
			switch (mod) {
				case 0: {
					return memWithReplace(SR_DS) + *register16(BR_BX);
				}
				break;
				case 1: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + ((int16_t)read8());
				}
				break;
				case 2: {
					return memWithReplace(SR_DS) + *register16(BR_BX) + read16();
				}
				break;
				default:
				return 0;
			}
			;
		}
		break;
		default:
		return 0;
	}
}
