class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirOfFiles;
        stringstream ss(path);
        string dir;

        while (getline(ss, dir, '/')) {
            if (dir == ".." && !dirOfFiles.empty()) {
                dirOfFiles.pop_back();
            } else if (dir != "." && dir != "" && dir != "..") {
                dirOfFiles.push_back(dir);
            }
        }

        string easy_path = "";
        for (const string& dirOfFile : dirOfFiles) {
            easy_path += "/" + dirOfFile;
        }

        return easy_path.empty() ? "/" : easy_path;
    }
};