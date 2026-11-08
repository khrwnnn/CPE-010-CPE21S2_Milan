#ifndef ASSETINVENTORY_H
#define ASSETINVENTORY_H

#include "BST.h"
#include <iostream>
#include <string>

class Asset{
    private:
        int assetID;
        std::string name;
        std::string status;
    public:
        Asset(int id = 0, std::string assetname="", std::string stat =""){
            assetID = id;
            name = assetname;
            status = stat;
        }
        
        int getAssetID() {
            return assetID;
        }

        std::string getAssetName() {
            return name;
        }

        std::string getStatus() {
            return status;
        }

        void displayAsset() {
            std::cout << "\nAsset ID: " << assetID << std::endl;
            std::cout << "Asset Name: " << name << std::endl;
            std::cout << "Status: " << status << std::endl;
        }

};

class AssetInventory {
private:
    static const int sizeAssets = 100;

    Asset assets[sizeAssets];
    int assetCount;

    BinarySearchTree<int>* assetBST;

public:
    // Constructor
    AssetInventory(){
        assetCount = 0;
        assetBST = nullptr;;
    }

    // Destructor
    ~AssetInventory() {
        delete assetBST;
    }

    // Add asset
    void addAsset(int id, std::string name, std::string status){
        if (assetBST != nullptr && assetBST->search(id)){
            std::cout << "Asset ID already exists.\n";
            return;
        }

        assets[assetCount] = Asset(id, name, status);
        assetCount++;

        if(assetBST == nullptr){
            assetBST = new BinarySearchTree<int>(id);
        }
        else{
            assetBST->insert(id);
        }

        std::cout << "Asset added successfully!" << std::endl;
    }

    // Search asset
    void searchAsset(int id) {
        if(assetBST == nullptr || !assetBST->search(id)){
            std::cout << "Asset not found.\n";
            return;
        }

        for(int i = 0; i <assetCount;i++){
            if(assets[i].getAssetID() == id){
                std::cout << "===== ASSET FOUND =====";
                assets[i].displayAsset();
                return;
            }
        }
    }

    // Display all assets
    void displayAssets() {
        if(assetCount == 0){
            std::cout << "Asset Inventory Empty." << std::endl;
            return;
        }

        std::cout << "\n===== ASSET INVENTORY =====" << std::endl;
        assetBST->inOrder();

        std::cout << "\n===== ASSET DETAILS =====" << std::endl;

        for(int i = 0; i < assetCount; i++){
            assets[i].displayAsset();
        }
    }

    // Update asset status
    void updateStatus(int id, std::string newStatus){
        for(int i = 0; i < assetCount; i++) {
            if(assets[i].getAssetID() == id){
                assets[i] = Asset(id, assets[i].getAssetName(), newStatus);
                std::cout << "Asset status updated successfully." << std::endl;
                return;
            }
        }

        std::cout << "Asset not found." << std::endl;
    }
};

#endif