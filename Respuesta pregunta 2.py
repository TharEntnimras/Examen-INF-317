
def cesar(mensaje, k):
    cifrado = ''
    for i in range(len(mensaje)):
        if mensaje[i] == ' ':
            cifrado = cifrado + mensaje[i]
        elif mensaje[i].isupper():
            cifrado = cifrado + chr((ord(mensaje[i])+k-65)%26+65)
        else:
            cifrado = cifrado + chr((ord(mensaje[i])+k-97)%26+97)
    return cifrado

mensaje = input("Ingrese mensaje a encriptar: ")
k = int(input("Ingrese llave: "))
m_cifrado = cesar(mensaje, k)
print("Mensaje encriptado: {}".format(m_cifrado))
