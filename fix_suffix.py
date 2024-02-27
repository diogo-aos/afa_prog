# this script will load recursively all files in the docs directory
# that have one of the extensions in a list

from pathlib import Path
import shutil

# list of file extensions to fix
exts = {
    '.beamerpdf': '-beamer.pdf',
    '.revealjshtml': '-revealjs.html',
    }

# list of directories to search
dirs = ['docs']

# list of files to ignore
ignore = []

# recursive search for files with the given extensions
for d in dirs:
    for ext, suffix in exts.items():
        for f in Path(d).rglob(f'*{ext}'):
            if not f.is_file() or f.name in ignore:
                continue
            new_name = str(f).replace(ext, suffix)
            print(f'{f} -> {new_name}')
            shutil.move(f, new_name)

            # check if html version of file exists
            # and fix links to original file
            html_f = Path(str(f).replace(ext, '.html'))
            if Path(html_f).is_file():
                original_basename = html_f.stem
                # load html and replace all links to original filename
                html_data = html_f.read_text()
                html_data = html_data.replace(ext, suffix)
                html_f.write_text(html_data)
