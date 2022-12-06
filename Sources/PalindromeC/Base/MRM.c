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
					int32_t address = *register32u(BR_EAX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EAX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EAX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_ECX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_ECX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_ECX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EDX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EDX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EDX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EBX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EBX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EBX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
							int32_t address = *register32u(BR_EAX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EAX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EAX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_ECX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ECX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ECX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_EDX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EDX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EDX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_EBX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EBX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EBX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_ESP_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ESP_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ESP_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = read32u() + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EBP_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EBP_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_ESI_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ESI_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ESI_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_EDI_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EDI_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EDI_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG32((uint64_t)memory, memory);
							return memory;;
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
					int32_t address = read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EBP_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EBP_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_ESI_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_ESI_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_ESI_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EDI_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EDI_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EDI_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EAX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EAX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EAX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_ECX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_ECX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_ECX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EDX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EDX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EDX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EBX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EBX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EBX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
							int32_t address = *register32u(BR_EAX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EAX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EAX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_ECX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ECX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ECX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_EDX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EDX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EDX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_EBX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EBX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EBX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_ESP_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ESP_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ESP_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = read32u() + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EBP_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EBP_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_ESI_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ESI_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ESI_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_EDI_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EDI_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EDI_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG16((uint64_t)memory, memory);
							return memory;;
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
					int32_t address = read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EBP_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EBP_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_ESI_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_ESI_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_ESI_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EDI_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EDI_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EDI_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EAX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EAX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EAX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_ECX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_ECX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_ECX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EDX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EDX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EDX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EBX_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EBX_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EBX_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
							int32_t address = *register32u(BR_EAX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EAX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EAX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_ECX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ECX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ECX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_EDX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EDX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EDX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_EBX_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EBX_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EBX_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_ESP_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ESP_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ESP_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = read32u() + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EBP_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EBP_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_ESI_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ESI_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ESI_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
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
							int32_t address = *register32u(BR_EDI_F) + shift;
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EDI_F) + shift + ((int16_t)read8());
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EDI_F) + shift + read32u();
							uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
							DATA_LOG8((uint64_t)memory, memory);
							return memory;;
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
					int32_t address = read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EBP_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EBP_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_ESI_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_ESI_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_ESI_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EDI_F);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EDI_F) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EDI_F) + read32u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register32u(BR_EAX_F);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EAX_F) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EAX_F) + read32u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register32u(BR_ECX_F);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_ECX_F) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_ECX_F) + read32u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register32u(BR_EDX_F);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EDX_F) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EDX_F) + read32u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register32u(BR_EBX_F);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EBX_F) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EBX_F) + read32u();
					uint8_t* memory =   address;
					return memory;;
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
							int32_t address = *register32u(BR_EAX_F) + shift;
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EAX_F) + shift + ((int16_t)read8());
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EAX_F) + shift + read32u();
							uint8_t* memory =   address;
							return memory;;
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
							int32_t address = *register32u(BR_ECX_F) + shift;
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ECX_F) + shift + ((int16_t)read8());
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ECX_F) + shift + read32u();
							uint8_t* memory =   address;
							return memory;;
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
							int32_t address = *register32u(BR_EDX_F) + shift;
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EDX_F) + shift + ((int16_t)read8());
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EDX_F) + shift + read32u();
							uint8_t* memory =   address;
							return memory;;
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
							int32_t address = *register32u(BR_EBX_F) + shift;
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EBX_F) + shift + ((int16_t)read8());
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EBX_F) + shift + read32u();
							uint8_t* memory =   address;
							return memory;;
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
							int32_t address = *register32u(BR_ESP_F) + shift;
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ESP_F) + shift + ((int16_t)read8());
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ESP_F) + shift + read32u();
							uint8_t* memory =   address;
							return memory;;
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
							int32_t address = read32u() + shift;
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EBP_F) + shift + ((int16_t)read8());
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EBP_F) + shift + read32u();
							uint8_t* memory =   address;
							return memory;;
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
							int32_t address = *register32u(BR_ESI_F) + shift;
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_ESI_F) + shift + ((int16_t)read8());
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_ESI_F) + shift + read32u();
							uint8_t* memory =   address;
							return memory;;
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
							int32_t address = *register32u(BR_EDI_F) + shift;
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 1: {
							int32_t address = *register32u(BR_EDI_F) + shift + ((int16_t)read8());
							uint8_t* memory =   address;
							return memory;;
						}
						break;
						case 2: {
							int32_t address = *register32u(BR_EDI_F) + shift + read32u();
							uint8_t* memory =   address;
							return memory;;
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
					int32_t address = read32u();
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EBP_F) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EBP_F) + read32u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register32u(BR_ESI_F);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_ESI_F) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_ESI_F) + read32u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register32u(BR_EDI_F);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register32u(BR_EDI_F) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register32u(BR_EDI_F) + read32u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI) + read16u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI) + ((int16_t)read8u());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI) + read16u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + read16u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + read16u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register16u(BR_SI);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_SI) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_SI) + read16u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register16u(BR_DI);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_DI) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_DI) + read16u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = read16u();
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + read16u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register16u(BR_BX);
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + ((int16_t)read8());
					uint8_t* memory =   address;
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + read16u();
					uint8_t* memory =   address;
					return memory;;
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
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_SI) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_DI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_DI) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_DI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BX);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG32((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_SI) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_DI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_DI) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_DI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BX);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG16((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + *register16u(BR_DI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + ((int16_t)read8u());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_SI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_SI) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_SI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_DI);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_DI) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_DI) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BP) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BP) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
					int32_t address = *register16u(BR_BX);
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 1: {
					int32_t address = *register16u(BR_BX) + ((int16_t)read8());
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
				}
				break;
				case 2: {
					int32_t address = *register16u(BR_BX) + read16u();
					uint8_t* memory = GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + address;
					DATA_LOG8((uint64_t)memory, memory);
					return memory;;
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
