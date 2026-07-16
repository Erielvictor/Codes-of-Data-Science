import yt_dlp


def baixar_video(url):
    ydl_opts = {
        # Altere para 'best' para pegar o melhor formato já pré-unido
        "format": "best",
        "outtmpl": "%(title)s.%(ext)s",
    }

    print("Iniciando o download... Aguarde.")
    with yt_dlp.YoutubeDL(ydl_opts) as ydl:
        ydl.download([url])
    print("\nDownload concluído com sucesso!")


if __name__ == "__main__":
    link = input("Cole a URL do vídeo do YouTube aqui: ")
    baixar_video(link)
